#!/usr/bin/env python
#
# @file    JavaCodeFile.py
# @brief   class for generating code file for the given class
# @author  Hovakim Grabski
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2015 by the California Institute of Technology
# (California, USA), the European Bioinformatics Institute (EMBL-EBI, UK)
# and the University of Heidelberg (Germany), with support from the National
# Institutes of Health (USA) under grant R01GM070923.  All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
# Neither the name of the California Institute of Technology (Caltech), nor
# of the European Bioinformatics Institute (EMBL-EBI), nor of the University
# of Heidelberg, nor the names of any contributors, may be used to endorse
# or promote products derived from this software without specific prior
# written permission.
# ------------------------------------------------------------------------ -->

from base_files import BaseJavaFile
from . java_functions import *
from util import query, strFunctions, global_variables


class JavaCodeFile(BaseJavaFile.BaseJavaFile):
    """Class for all Java Code files"""

    def __init__(self, class_object, represents_class=True):

        self.brief_description = \
            'Implementation  of the {0} class.'.format(class_object['name'])
        BaseJavaFile.BaseJavaFile.__init__(self, class_object['name'], 'java',
                                         class_object['attribs'])

        # members from object
        # TODO will need something similar for the import modules
        if represents_class:
            self.expand_class(class_object)

            # TODO GSOC 2016 JSBML
            self.expand_import_modules()
            # self.expand_mandatory()
            self.expand_jsbml_methods()


        # self.jsbml_modules = jsbml_data_tree.jsbml_modules
        #print(self.jsbml_data_tree)
    ########################################################################

    # Functions for writing the class
    def write_class(self):
        # self.write_forward_class()
        # TODO for now only generate attribute functions
        self.write_constructors()

        self.write_attribute_functions()

        # TODO GSOC MANDATORY
        self.write_mandatory_functions()


        # self.write_child_element_functions()
        # self.write_listof_functions()
        # self.write_child_lo_element_functions()
        # self.write_concrete_functions()

        # TODO write hash, read, write
        self.write_general_functions()
        # self.write_functions_to_retrieve()
        # if self.document:
        #     self.write_document_error_log_functions()
        # self.write_protected_functions()
        # if self.add_impl is not None and not self.is_list_of:
        #     self.copy_additional_file(self.add_impl)

    def write_c_code(self):
        self.is_java_api = False
        if not self.is_list_of:
            self.write_constructors()
            self.write_attribute_functions()
            self.write_child_element_functions()
            self.write_child_lo_element_functions()
            self.write_concrete_functions()
            self.write_general_functions()
        else:
            self.write_attribute_functions()
            self.write_listof_functions()

    ########################################################################
    # Functions for writing specific includes and forward declarations

    def write_forward_class(self):
        if len(self.concretes) == 0:
            return
        for element in self.concretes:
            self.write_line('class {0};'.format(element['element']))
        self.skip_line()




    def write_jsbml_class_header(self):
        abstract = self.jsbml_class_header_and_import['abstract']
        class_name = self.jsbml_class_header_and_import['className']
        extends = self.jsbml_class_header_and_import['extends']
        implement_modules = self.jsbml_class_header_and_import['implements']
        if abstract == False:
            write_abstract = ''
        else:
            write_abstract = 'abstract '
        line_to_write = 'public {0}class {1} '.format(write_abstract, class_name)
        extends_len = len(extends)
        if extends_len == 1:
            line_to_write += 'extends {0}'.format(extends[0])
        elif extends_len > 1:
            line_to_write += ' extends'
            for n in range(0, extends_len-1):
                line_to_write = line_to_write + extends[n] + ', '

        implement_len = len(implement_modules)
        if implement_len == 1:
            line_to_write += ' implements {0}'.format(implement_modules[0])
        elif implement_len > 1:
            line_to_write += ' implements '
            for n in range(0, implement_len-1):
                print(implement_modules[n])
                line_to_write += implement_modules[n] + ', '
            line_to_write = line_to_write + implement_modules[-1]
            #print(line_to_write)

        self.line_length = 120 # TODO not a great solution
        self.write_line_jsbml(line_to_write) # TODO need to fix about spaces
        #self.write_jsbml_line_verbatim(line_to_write)
        self.file_out.write('\n') # TODO not a good solution
        self.line_length = 79


    # function to write the data members
    def write_data_members(self, attributes):
        for i in range(0, len(attributes)):
            if attributes[i]['attType'] != 'string':
                self.write_line('{0} {1};'.format(attributes[i]['attTypeCode'],
                                                  attributes[i]['memberName']))
            else:
                self.write_line('std::string {0};'
                                .format(attributes[i]['memberName']))
            if attributes[i]['isNumber'] is True \
                    or attributes[i]['attType'] == 'boolean':
                self.write_line('bool mIsSet{0};'
                                .format(attributes[i]['capAttName']))
        if self.overwrites_children:
            self.write_line('std::string mElementName;')

    ########################################################################

    # function to write the constructors
    def write_constructors(self):
        constructor = Constructors.Constructors(self.language,
                                                self.is_java_api,
                                                self.class_object,
                                                self.jsbml_data_tree,
                                                self.jsbml_methods,
                                                self.extends_modules
                                                )
        self.skip_line()
        if self.is_java_api and not self.is_plugin:
            code = constructor.write_simple_constructor()
            self.write_function_implementation(code)

            code = constructor.write_level_version_constructor()
            self.write_function_implementation(code)

            code = constructor.write_id_constructor()
            self.write_function_implementation(code)


            code = constructor.write_id_level_version_constructor()
            self.write_function_implementation(code)

            self.line_length = 90
            code = constructor.write_id_name_level_version_constructor()
            self.write_function_implementation(code)
            self.line_length = 79

            code = constructor.write_copy_constructor()
            self.write_function_implementation(code)

            code = constructor.write_init_defaults_constructor()
            self.write_function_implementation(code)

            # code = constructor.write_namespace_constructor()
            # self.write_function_implementation(code)
        # elif self.is_plugin:
        #     code = constructor.write_uri_constructor()
        #     self.write_function_implementation(code)
        elif self.has_std_base: # TODO constructor tricky This is tricky
            for i in range(0, len(self.concretes)+1):
                code = constructor.write_level_version_constructor(i)
                self.write_function_implementation(code)
        else:
            code = constructor.write_level_version_constructor(-1)
            self.write_function_implementation(code)


        # TODO after main constructors
        # code = constructor.write_copy_constructor()
        # self.write_function_implementation(code)


        # TODO write_equals problematic
        code = constructor.write_equals()
        self.write_function_implementation(code)
        #

        # Clone need @override
        code = constructor.write_clone()
        self.write_function_implementation(code)


    ########################################################################

    # Functions for writing the attribute manipulation functions
    # these are for attributes and elements that occur as a single child

    def write_function_java(self, code):
        #print('Ylo friend')
        if code is not None:
            self.write_function_implementation(code)

        # function to write the get/set/isSet/unset functions for attributes

    def write_mandatory_functions(self):
        attrib_functions = MandatoryFunctions.MandatoryFunctions(self.language,
                                                           self.is_java_api,
                                                           self.is_list_of,
                                                           self.class_object,
                                                           self.jsbml_data_tree,
                                                           self.jsbml_methods)

        num_attributes = attrib_functions.get_num_attributes()
        print('num attributes ', num_attributes)
        #
        # # # TODO how to write instance methods
        for i in range(0, num_attributes):
            code = attrib_functions.write_mandatory(True, i)
            # self.write_function_implementation(code)
            self.write_function_java(code)

    # function to write the get/set/isSet/unset functions for attributes
    def write_attribute_functions(self):
        attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                           self.is_java_api,
                                                           self.is_list_of,
                                                           self.class_object,
                                                           self.jsbml_data_tree,
                                                           self.jsbml_methods)
        num_attributes = len(self.class_attributes)


        #TODO how to write instance methods
        for i in range(0, num_attributes):
            code = attrib_functions.write_get(True, i)
            # self.write_function_implementation(code)
            self.write_function_java(code)


            # TODO GSOC 2016 get Object Instance
            code = attrib_functions.write_get_instance(True, i)
            # self.write_function_implementation(code)
            self.write_function_java(code)

            # code = attrib_functions.write_get_string_for_enum(True, i)
            # self.write_function_implementation(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_is_set(True, i)
            # self.write_function_implementation(code)
            self.write_function_java(code)

            code = attrib_functions.write_is_set_instance(True, i)
            self.write_function_java(code)

            # code = attrib_functions.write_get_num_for_vector(True, i) # IsSetID for JSBML not neccessary
            # self.write_function_implementation(code)



        # TODO SIdRef write function 2 times (String, OriginalType)
        for i in range(0, num_attributes):

            curr_attribute = attrib_functions.get_attribute(True, i)
            #print('Curr_attribute ', curr_attribute)



            code = attrib_functions.write_set(True, i)
            self.write_function_java(code)

            similar_num_attributes = attrib_functions.get_similar_num_attributes()
            for y in range(0, similar_num_attributes):
                code = attrib_functions.write_similar_functions(True, i, y)
                self.write_function_java(code)



            # self.write_function_implementation(code)

            # code = attrib_functions.write_set_string_for_enum(True, i)
            # self.write_function_implementation(code)
            #
            # code = attrib_functions.write_add_element_for_vector(True, i)
            # self.write_function_implementation(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_unset(True, i)
            self.write_function_java(code)
            # self.write_function_implementation(code)

    # function to write the get/set/isSet/unset functions for single
    # child elements
    def write_child_element_functions(self, override=None):
        if override is None:
            if not self.has_children:
                return

            attrib_functions = SetGetFunctions.\
                SetGetFunctions(self.language, self.is_java_api,
                                self.is_list_of, self.class_object)

            num_elements = len(self.child_elements)
        else:
            attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                               self.is_java_api,
                                                               self.is_list_of,
                                                               override)
            num_elements = 1

        for i in range(0, num_elements):
            code = attrib_functions.write_get(False, i)
            self.write_function_implementation(code)

            code = attrib_functions.write_get(False, i, const=False)
            self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_is_set(False, i)
            self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_set(False, i)
            self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_create(False, i)
            if override is None and code is None \
                    and 'concrete' in self.child_elements[i]:
                # need to write creates for the concrete
                member = self.child_elements[i]['memberName']
                concrete = self.child_elements[i]['concrete']
                concretes = query.get_concretes(self.class_object['root'],
                                                concrete)
                for j in range(0, len(concretes)):
                    code = attrib_functions\
                        .write_create_concrete_child(concretes[j], member)
                    self.write_function_implementation(code)
            else:
                self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_unset(False, i)
            self.write_function_implementation(code)

    ########################################################################

    # Functions for writing general functions

    def write_general_functions(self):
        gen_functions = GeneralFunctions.GeneralFunctions(self.language,
                                                          self.is_java_api,
                                                          self.is_list_of,
                                                          self.class_object)
        code = gen_functions.write_rename_sidrefs()
        self.write_function_implementation(code)

        if not self.is_plugin:
            code = gen_functions.write_get_element_name()
            self.write_function_implementation(code)

        code = gen_functions.write_set_element_name()
        self.write_function_implementation(code, exclude=True)

        if not self.is_plugin:
            code = gen_functions.write_get_typecode()
            self.write_function_implementation(code)

        code = gen_functions.write_get_item_typecode()
        self.write_function_implementation(code)

        code = gen_functions.write_has_required_attributes()
        self.write_function_implementation(code)

        code = gen_functions.write_has_required_elements()
        self.write_function_implementation(code)

        code = gen_functions.write_write_elements()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_accept()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_set_document()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_write()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_connect_to_child()
        self.write_function_implementation(code, exclude=True)

        if self.is_plugin:
            code = gen_functions.write_connect_to_parent()
            self.write_function_implementation(code, exclude=True)

        if global_variables.is_package:
            code = gen_functions.write_enable_package()
            self.write_function_implementation(code, exclude=True)

        if self.is_doc_plugin:
            code = gen_functions.write_is_comp_flat()
            self.write_function_implementation(code, exclude=True)

            code = gen_functions.write_check_consistency()
            self.write_function_implementation(code, exclude=True)

            code = gen_functions.write_read_attributes()
            self.write_function_implementation(code, exclude=True)

    ########################################################################

    # Retrieve element functions

    def write_functions_to_retrieve(self):
        if not query.has_children(self.attributes):
            return

        gen_functions = \
            GlobalQueryFunctions.GlobalQueryFunctions(self.language,
                                                      self.is_java_api,
                                                      self.is_list_of,
                                                      self.class_object)
        code = gen_functions.write_get_by_sid()
        self.write_function_implementation(code)

        code = gen_functions.write_get_by_metaid()
        self.write_function_implementation(code)

        code = gen_functions.write_get_all_elements()
        self.write_function_implementation(code)

        if self.is_plugin:
            code = gen_functions.write_append_from()
            self.write_function_implementation(code, True)
    ########################################################################

    # Functions for writing the attribute manipulation functions
    # these are for attributes and elements that occur as a single child

    # function to write additional functions on a document for another library
    def write_document_error_log_functions(self):

        attrib_functions = SetGetFunctions.\
            SetGetFunctions(self.language, self.is_java_api,
                            self.is_list_of, self.class_object)
        num_elements = len(self.child_elements)
        # add error log and ns to child elements
        att_tc = 'XMLNamespaces*'
        if not global_variables.is_package:
            att_tc = 'LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*'
        element = dict({'name': 'Namespaces',
                        'isArray': False,
                        'attTypeCode': att_tc,
                        'capAttName': 'Namespaces',
                        'attType': 'element',
                        'memberName': 'm{0}Namespaces'.format(global_variables.prefix)})

        errelement = dict({'name': '{0}ErrorLog'.format(global_variables.prefix),
                           'isArray': False,
                           'attTypeCode': '{0}ErrorLog*'.format(global_variables.prefix),
                           'capAttName': 'ErrorLog',
                           'attType': 'element',
                           'memberName': 'mErrorLog'})

        self.child_elements.append(element)
        self.child_elements.append(errelement)

        code = attrib_functions.write_get(False, num_elements, True, True)
        self.write_function_implementation(code)

        code = attrib_functions.write_get(False, num_elements, False, True)
        self.write_function_implementation(code)

        code = attrib_functions.write_get(False, num_elements+1, True)
        self.write_function_implementation(code)

        code = attrib_functions.write_get(False, num_elements+1, False)
        self.write_function_implementation(code)

        self.child_elements.remove(errelement)
        self.child_elements.remove(element)

        # preserve existing values
        existing = dict()
        self.class_object['element'] = '{0}Error'.format(global_variables.prefix)
        self.class_object['parent'] = dict({'name': '{0}Document'.format(global_variables.prefix)})
        self.class_object['memberName'] = 'mErrorLog'
        lo_functions = ListOfQueryFunctions\
            .ListOfQueryFunctions(self.language, self.is_java_api,
                                  self.is_list_of,
                                  self.class_object)

        code = lo_functions.write_get_element_by_index(is_const=False)
        self.write_function_implementation(code)

        code = lo_functions.write_get_element_by_index(is_const=True)
        self.write_function_implementation(code)

        code = lo_functions.write_get_num_element_function()
        self.write_function_implementation(code)

        parameter = dict({'name': 'severity',
                          'type': 'unsigned int'})
        code = lo_functions.write_get_num_element_function(parameter)
        self.write_function_implementation(code)

    ########################################################################

    # concrete class functions

    def write_concrete_functions(self):
        conc_functions = \
            ConcreteClassFunctions.ConcreteClassFunctions(self.language,
                                                          self.is_java_api,
                                                          self.is_list_of,
                                                          self.class_object)
        for i in range(0, len(self.concretes)):
            code = conc_functions.write_is_foo(i)
            self.write_function_implementation(code)

    ########################################################################

    # Protected functions

    def write_protected_functions(self):
        protect_functions = \
            ProtectedFunctions.ProtectedFunctions(self.language,
                                                  self.is_java_api,
                                                  self.is_list_of,
                                                  self.class_object)
        exclude = True
        code = protect_functions.write_create_object()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_add_expected_attributes()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_read_attributes()
        self.write_function_implementation(code, exclude)
        if 'num_versions' in self.class_object \
                and self.class_object['num_versions'] > 1:
            for i in range(0, self.class_object['num_versions']):
                code = protect_functions.write_read_version_attributes(i+1)
                self.write_function_implementation(code, exclude)

        code = protect_functions.write_read_other_xml()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_write_attributes()
        self.write_function_implementation(code, exclude)
        if 'num_versions' in self.class_object \
                and self.class_object['num_versions'] > 1:
            for i in range(0, self.class_object['num_versions']):
                code = protect_functions.write_write_version_attributes(i+1)
                self.write_function_implementation(code, exclude)

        code = protect_functions.write_write_xmlns()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_is_valid_type_for_list()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_set_element_text()
        self.write_function_implementation(code, exclude)

    ########################################################################

    # Functions for writing functions for the main ListOf class

    def write_listof_functions(self):
        if not self.is_list_of:
            return

        lo_functions = ListOfQueryFunctions\
            .ListOfQueryFunctions(self.language, self.is_java_api,
                                  self.is_list_of,
                                  self.class_object)

        code = lo_functions.write_get_element_by_index(is_const=False)
        self.write_function_implementation(code)

        code = lo_functions.write_get_element_by_index(is_const=True)
        self.write_function_implementation(code)

        code = lo_functions.write_get_element_by_id(is_const=False)
        self.write_function_implementation(code)

        code = lo_functions.write_get_element_by_id(is_const=True)
        self.write_function_implementation(code)

        code = lo_functions.write_remove_element_by_index()
        self.write_function_implementation(code)

        code = lo_functions.write_remove_element_by_id()
        self.write_function_implementation(code)

        if self.is_java_api:
            code = lo_functions.write_add_element_function()
            self.write_function_implementation(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_implementation(code)

            for i in range(0, len(self.concretes)+1):
                code = lo_functions.write_create_element_function(i)
                self.write_function_implementation(code)

            for i in range(0, len(self.sid_refs)):
                code = lo_functions.write_lookup(self.sid_refs[i])
                self.write_function_verbatim(code)

                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                             const=True)
                self.write_function_implementation(code)

                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                             const=False)
                self.write_function_implementation(code)

    # main function to write the functions dealing with a child listOf element
    def write_child_lo_element_functions(self):
        num_elements = len(self.child_lo_elements)
        for i in range(0, num_elements):
            element = self.child_lo_elements[i]
            element['std_base'] = self.std_base
            element['package'] = self.package
            element['is_header'] = self.is_header
            element['is_plugin'] = self.is_plugin
            if self.is_plugin:
                element['plugin'] = self.class_name
            if 'concrete' in element:
                element['concretes'] = query.get_concretes(
                    self.class_object['root'], element['concrete'])
            lo_functions = ListOfQueryFunctions\
                .ListOfQueryFunctions(self.language, self.is_java_api,
                                      self.is_list_of,
                                      element)
            code = lo_functions.write_get_list_of_function(is_const=True)
            self.write_function_implementation(code)

            code = lo_functions.write_get_list_of_function(is_const=False)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_index(is_const=False)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_index(is_const=True)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_id(is_const=False)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_id(is_const=True)
            self.write_function_implementation(code)

            sid_ref = query.get_sid_refs_for_class(element)
            for j in range(0, len(sid_ref)):
                if self.is_list_of:
                    code = lo_functions.write_lookup(sid_ref[j])
                    self.write_function_verbatim(code)

                code = \
                    lo_functions.write_get_element_by_sidref(sid_ref[j],
                                                             const=True)
                self.write_function_implementation(code)

                code = \
                    lo_functions.write_get_element_by_sidref(sid_ref[j],
                                                             const=False)
                self.write_function_implementation(code)

            code = lo_functions.write_add_element_function()
            self.write_function_implementation(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_implementation(code)

            if 'concretes' in element:
                for n in range(0, len(element['concretes'])):
                        code = lo_functions.write_create_element_function(n+1)
                        self.write_function_implementation(code)
            else:
                code = lo_functions.write_create_element_function()
                self.write_function_implementation(code)

            code = lo_functions.write_remove_element_by_index()
            self.write_function_implementation(code)

            code = lo_functions.write_remove_element_by_id()
            self.write_function_implementation(code)

            # this tackles the situation where a listOfFoo class also
            # contains an element of another type
            # eg qual:ListOfFunctionTerms contains a DefaultTerm
            if not self.is_plugin:
                element_children = \
                    query.get_other_element_children(self.class_object, element)

                for j in range(0, len(element_children)):
                    child_class = self.create_lo_other_child_element_class(
                        element_children[0], self.class_name)
                    self.write_child_element_functions(child_class)
    ########################################################################


    ########################################################################

    # Write file
    # TODO add variable whether extension or parser
    def write_package_include(self):
        if global_variables.is_package:
            curr_include_line = 'package org.sbml.{0}.ext.{1};'.format(self.language, self.package.lower())
            #print('curr_include_line is ', curr_include_line)
            self.write_line_verbatim(curr_include_line)

    def close_jsbml_class_header(self):
        self.down_indent()
        self.file_out.write('}\n')

    def write_jsbml_class_variables(self):
        self.up_indent()
        self.write_serial_version_comment()
        # TODO need to change serialVersionUID
        line = 'private static final long     serialVersionUID = {0}L;'.format(self.serialVersionUID)
        self.write_line(line)

        attributes = self.class_attributes
        for attribute in attributes:
            #print(attribute['memberName'])
            cap_att_name = attribute['capAttName']
            if str(cap_att_name) != 'Id' and str(cap_att_name) != 'Name':
                self.write_variable_comment()
                return_type = attribute['JClassType']
                member_name = attribute['name']
                line = 'private {0} {1};'.format(return_type, member_name)
                self.write_line(line)
        self.down_indent()

        # TODO for writing imports

    def write_java_imports(self):
        # TODO mockup function
        self.skip_line()
        java_modules = self.jsbml_class_header_and_import['javaModules']
        if len(java_modules) > 0:
            for module in java_modules:
                javaModuleLine = 'import {0}'.format(module)
                self.write_jsbml_line_verbatim(javaModuleLine)
            self.skip_line()

        jsbml_modules = self.jsbml_class_header_and_import['jsbmlModules']
        if len(jsbml_modules) > 0:
            for module in jsbml_modules:
                jsbmlModuleLine = 'import org.sbml.jsbml.{0}'.format(module)
                self.write_jsbml_line_verbatim(jsbmlModuleLine)
            self.skip_line()

    # TODO need to add import
    def write_file(self):
        BaseJavaFile.BaseJavaFile.write_file(self)
        self.write_package_include()
        self.write_java_imports()
        #self.write_general_includes()
        BaseJavaFile.BaseJavaFile.write_jsbml_types_doc(self)
        self.write_jsbml_class_header()
        self.write_jsbml_class_variables()
        self.write_class()
        self.close_jsbml_class_header()
        # self.write_cpp_end()
        # if not self.is_plugin:
        #     self.write_c_code()
        # self.write_cppns_end()
