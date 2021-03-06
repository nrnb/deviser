#!/usr/bin/env python
#
# @file    BaseXMLFile.py
# @brief   base class for all XML test files to be generated
# @author  Frank Bergmann
# @author  Sarah Keating
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


from . import BaseFile
from xml.dom.minidom import *
from util import strFunctions, query


class BaseXMLFile(BaseFile.BaseFile):
    """Common base class for all interface files"""

    def __init__(self, name, package, reqd, ext='xml'):
        BaseFile.BaseFile.__init__(self, name, ext)

        self.pkg = package
        self.corens = 'http://www.sbml.org/sbml/level3/version1/core'
        self.pkgns = 'http://www.sbml.org/sbml/level3/version1/{0}/version1' \
                     ''.format(self.pkg)
        self.reqd = reqd

        self.rngns = 'http://relaxng.org/ns/structure/1.0'
        self.xmlschema = 'http://www.w3.org/2001/XMLSchema-datatypes'

        self.comment_start = '<!--'
        self.comment_end = '-->'

        self.start_id = 1

        self.impl = getDOMImplementation()

        self.doc = None

    #########################################################################
    # main writing function

    def write_xml(self, tree, error_code=None):
        self.create_document(error_code)
        for i in range(0, len(tree)):
            element = self.create_top_object(tree[0])
            self.doc.documentElement.appendChild(element)
        str_xml = self.doc.toprettyxml(indent='    ', encoding='UTF-8')
        lines = str_xml.split('\n')
        for line in lines:
            self.write_line_verbatim(line)

    ########################################################################
    # create elements of the document

    def create_rng_document(self):
        self.doc = self.impl.createDocument(self.rngns, 'grammar', None)
        top_element = self.doc.documentElement
        top_element.setAttributeNS(self.rngns, 'xmlns', self.rngns)
        top_element.setAttributeNS(self.rngns, 'ns', self.pkgns)
        top_element.setAttributeNS(self.rngns, 'datatypeLibrary', self.xmlschema)


    def create_document(self, error_code=None):
        self.doc = self.impl.createDocument(self.corens, 'sbml', None)
        top_element = self.doc.documentElement
        top_element.setAttributeNS(self.corens, 'xmlns', self.corens)
        top_element.setAttributeNS(self.corens, 'level', '3')
        top_element.setAttributeNS(self.corens, 'version', '1')
        if error_code:
            if error_code == 'incorrect_ns':
                top_element.setAttributeNS(self.pkgns, 'xmlns:{0}'.format(self.pkg),
                                           'http://incorrect')
            elif error_code != 'missing_ns':
                top_element.setAttributeNS(self.pkgns, 'xmlns:{0}'.format(self.pkg),
                                           self.pkgns)
        else:
            top_element.setAttributeNS(self.pkgns, 'xmlns:{0}'.format(self.pkg),
                                       self.pkgns)
        if error_code:
            if error_code == 'incorrect_value_reqd':
                reqd = 'true'
                if self.reqd == 'true':
                    reqd = 'false'
                top_element.setAttributeNS(self.pkgns,
                                           '{0}:required'.format(self.pkg),
                                           reqd)
            elif error_code == 'incorrect_type_reqd':
                top_element.setAttributeNS(self.pkgns,
                                           '{0}:required'.format(self.pkg),
                                           '-3.4')
            elif error_code != 'missing_reqd':
                top_element.setAttributeNS(self.pkgns,
                                           '{0}:required'.format(self.pkg),
                                           self.reqd)
        else:
            top_element.setAttributeNS(self.pkgns,
                                       '{0}:required'.format(self.pkg),
                                       self.reqd)



    def create_top_object(self, tree):
        name = strFunctions.lower_first(tree['base'])
        if tree['ext'] == 'core':
            element = self.create_object(tree)
        return element


    def create_object(self, parent):
        if 'base' in parent:
            name = strFunctions.lower_first(parent['base'])
        elif 'name' in parent:
            name = strFunctions.lower_first(parent['name'])
        else:
            name = 'FIXME'

        if 'ext' in parent:
            ext = parent['ext']
        else:
            ext = self.pkg

        if name == 'math':
            return self.create_math_element()
        if ext != 'core':
            name = '{0}:{1}'.format(self.pkg, name)

        attribs = []
        if 'attribs' in parent:
            attribs = self.get_attributes(parent['attribs'], ext)

        return self.create_element(name, attribs, parent)


    def create_element(self, name, attribs, parent):
        children = parent['children']
        element = self.doc.createElement('{0}'.format(name))
        for i in range (0, len(attribs)):
            element.setAttribute('{0}'.format(attribs[i]['name']), attribs[i]['value'])
        for i in range(0, len(children)):
            subelement = self.create_object(children[i])
            element.appendChild(subelement)
        return element

    def create_math_element(self):
        element = self.doc.createElement('{0}'.format('math'))
        element.setAttribute('xmlns', 'http://www.w3.org/1998/Math/MathML')
        return element

    ######################################################################

    # functions to make nice sets of attributes

    def get_sensible_value(self, attribute):
        value = ''
        att_type = attribute['type']
        if att_type == 'boolean':
            value = 'false'
        elif query.is_number(att_type):
            value = '0'
        elif att_type == 'SId':
            value = 'id_{0}'.format(self.start_id)
            self.start_id += 1
        elif att_type == 'enum':
            value = query.get_first_enum_value(attribute)
        elif att_type == 'SBO':
            value = 'SBO:0000001'
        else:
            value = 'someString'
        return value

    def get_attributes(self, attributes, pkg):
        attrib_list = []
        for attrib in attributes:
            att_type = attrib['type']
            if query.is_element(att_type):
                continue
            if 'ext' in attrib:
                pkg = attrib['ext']
            if pkg == 'core':
                name = attrib['xml_name']
            else:
                name = '{0}:{1}'.format(pkg, attrib['xml_name'])
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
        return attrib_list
