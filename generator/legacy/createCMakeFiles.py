#!/usr/bin/env python
#
# @file    createCMakeFiles.py
# @brief   create the CMake files
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2014 by the California Institute of Technology
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

import sys
import os
import fileHeaders
import strFunctions

	
def writeSrcListsFile(name, nameOfPackage, plugins, classes):
	capName = name.upper()
	uname = strFunctions.cap(name)
	codeName = 'CMakeLists.txt'
	fileOut = open(codeName, 'w')
	fileOut.write('# This CMake file integrates the binding source with the libsbml source tree\n#\n\n\n'.format(name))
	fileOut.write('# include common functions (used for copying / removing files)\n')
	fileOut.write('if(NOT EXISTS ${LIBSBML_SOURCE}/common.cmake)\n')
	fileOut.write('  message(FATAL_ERROR "Invalid libsbml source directory")\n')
	fileOut.write('endif()\n\n')
	fileOut.write('include(${LIBSBML_SOURCE}/common.cmake)\n\n')
	fileOut.write('# specify the package files\n')
	fileOut.write('set(PACKAGE_FILES\n\n')	
	fileOut.write('  # forward declaractions\n')
	fileOut.write('  "common/{0}fwd.h"\n'.format(name))
	fileOut.write('  "common/{0}ExtensionTypes.h"\n\n'.format(uname))		
	fileOut.write('  # extension points\n')
	fileOut.write('  "extension/{0}Extension.h"\n'.format(uname))
	for i in range (0, len(plugins)):
		fileOut.write('  "extension/{0}{1}Plugin.h"\n'.format(nameOfPackage, plugins[i]['sbase']))
	fileOut.write('  "extension/{0}Extension.cpp"\n'.format(uname))
	for i in range (0, len(plugins)):
		fileOut.write('  "extension/{0}{1}Plugin.cpp"\n'.format(nameOfPackage, plugins[i]['sbase']))
	fileOut.write('\n  #new SBML classes\n')
	for i in range (0, len(classes)):
		fileOut.write('  "sbml/{0}.h"\n'.format(classes[i]['name']))
	for i in range (0, len(classes)):
		fileOut.write('  "sbml/{0}.cpp"\n'.format(classes[i]['name']))
	fileOut.write('\n  #test cases\n')
	fileOut.write('\n\n')
	fileOut.write('   )\n\n')
	fileOut.write('# specify the files for the language bindings\n')
	fileOut.write('set(BINDING_FILES\n\n')
	fileOut.write('  # C# bindings\n')
	fileOut.write('  "bindings/csharp/local-downcast-extension-{0}.i"\n'.format(name))
	fileOut.write('  "bindings/csharp/local-downcast-namespaces-{0}.i"\n'.format(name))
	fileOut.write('  "bindings/csharp/local-packages-{0}.i"\n\n'.format(name))
	fileOut.write('  # java bindings\n')
	fileOut.write('  "bindings/java/local-downcast-extension-{0}.i"\n'.format(name))
	fileOut.write('  "bindings/java/local-downcast-namespaces-{0}.i"\n'.format(name))
	fileOut.write('  "bindings/java/local-packages-{0}.i"\n\n'.format(name))
	fileOut.write('  # perl bindings\n')
	fileOut.write('  "bindings/perl/local-downcast-extension-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/perl/local-downcast-packages-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/perl/local-downcast-namespaces-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/perl/local-downcast-plugins-{0}.cpp"\n\n'.format(name))
	fileOut.write('  # python bindings\n')
	fileOut.write('  "bindings/python/local-downcast-extension-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/python/local-downcast-packages-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/python/local-downcast-namespaces-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/python/local-downcast-plugins-{0}.cpp"\n\n'.format(name))
	fileOut.write('  # ruby bindings\n')
	fileOut.write('  "bindings/ruby/local-downcast-extension-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/ruby/local-downcast-packages-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/ruby/local-downcast-namespaces-{0}.cpp"\n'.format(name))
	fileOut.write('  "bindings/ruby/local-downcast-plugins-{0}.cpp"\n\n'.format(name))
	fileOut.write('  # generic swig bindings\n')
	fileOut.write('  "bindings/swig/{0}-package.h"\n'.format(name))
	fileOut.write('  "bindings/swig/{0}-package.i"\n\n'.format(name))
	fileOut.write('   )\n\n')
	fileOut.write('if(MODE STREQUAL "integrate")\n')
	fileOut.write('  # integrate the package with the specified libsbml source directory\n\n')
	fileOut.write('  # copy the CMake script that integrates the source files with libsbml-5\n')
	fileOut.write('  copy_file("../{0}-package.cmake" '.format(name))
	fileOut.write('${LIBSBML_SOURCE})\n')
	fileOut.write('  copy_file("{0}-package.cmake" '.format(name))
	fileOut.write('${LIBSBML_SOURCE}/src)\n\n')
	fileOut.write('  # copy language binding files\n')
	fileOut.write('  foreach(bindingFile ${BINDING_FILES})\n')	
	fileOut.write('    copy_file_to_subdir( ${bindingFile} ${LIBSBML_SOURCE}/src)\n')
	fileOut.write('  endforeach()\n\n')
	fileOut.write('  # copy package files\n')
	fileOut.write('  foreach(packageFile ${PACKAGE_FILES})\n')	
	fileOut.write('    copy_file_to_subdir( ${packageFile} ${LIBSBML_SOURCE}')
	fileOut.write('/src/packages/{0})\n'.format(name))
	fileOut.write('  endforeach()\n\n')
	fileOut.write('  # copy header files to include directory just in case\n')
	fileOut.write('  foreach(dir common extension sbml)\n\n')
	fileOut.write('    # copy files\n')
	fileOut.write('    copy_files( ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/\n')
	fileOut.write('      ${LIBSBML_SOURCE}')
	fileOut.write('/include/sbml/{0} *.h )\n\n'.format(name))
	fileOut.write('  endforeach()\n\n')
	fileOut.write('  add_custom_target(integrate ALL)\n\n')
	fileOut.write('  message(STATUS "Finished integrating the SBML {0} package with the libsbml source tree in:")\n'.format(name))
	fileOut.write('  message(STATUS "${LIBSBML_SOURCE}")\n\n')
	fileOut.write('elseif(MODE STREQUAL "remove")\n')
	fileOut.write('  # remove all package files from the specified libsbml source directory\n\n')
	fileOut.write('  remove_file(${LIBSBML_SOURCE}')
	fileOut.write('/{0}-package.cmake)\n'.format(name))
	fileOut.write('  remove_file(${LIBSBML_SOURCE}')
	fileOut.write('/src/{0}-package.cmake)\n\n'.format(name))
	fileOut.write('  # copy language binding files\n')
	fileOut.write('  foreach(bindingFile ${BINDING_FILES})\n')	
	fileOut.write('    remove_file_in_subdir( ${bindingFile} ${LIBSBML_SOURCE}/src)\n')
	fileOut.write('  endforeach()\n\n')
	fileOut.write('  # copy package files\n')
	fileOut.write('  foreach(packageFile ${PACKAGE_FILES})\n')	
	fileOut.write('    remove_file_in_subdir( ${packageFile} ${LIBSBML_SOURCE}')
	fileOut.write('/src/packages/{0})\n'.format(name))
	fileOut.write('  endforeach()\n\n')
	fileOut.write('  # delete package directory\n')
	fileOut.write('  file(REMOVE ${LIBSBML_SOURCE}')
	fileOut.write('/src/packages/{0})\n'.format(name))
	fileOut.write('  file(REMOVE_RECURSE ${LIBSBML_SOURCE}')
	fileOut.write('/include/sbml/{0})\n\n'.format(name))
	fileOut.write('  add_custom_target(remove ALL)\n\n')
	fileOut.write('  message(STATUS "Finished removing the SBML {0} package from the libsbml source tree in:")\n'.format(name))
	fileOut.write('  message(STATUS "${LIBSBML_SOURCE}")\n\n')
	fileOut.write('endif()\n\n')



	
def writeTopLevelListsFile(name):
	capName = name.upper()
	codeName = 'CMakeLists.txt'
	fileOut = open(codeName, 'w')
	fileOut.write('# This CMake Package integrates the SBML {0} package with libsbml 5\n#\n\n\n'.format(name))
	fileOut.write('cmake_minimum_required(VERSION 2.8)\n\n')
	fileOut.write('# the project name should be the same name as the SBML package\n')
	fileOut.write('project({0})\n\n'.format(name))
	fileOut.write('set(MODE "integrate" CACHE STRING "The operation to perform, valid options are integrate|compile|remove.")\n')
	fileOut.write('set(LIBSBML_SOURCE "$ENV{HOME}/Development/libsbml-5/" CACHE PATH "Path to the libsbml source distribution")\n')
	fileOut.write('set(EXTRA_LIBS "xml2;bz2;z" CACHE STRING "List of Libraries to link against" )\n\n')
	fileOut.write('if(MODE STREQUAL "compile")\n')
	fileOut.write('  # compile the package and link it against an existing libsbml-5 version\n')
	fileOut.write('  # file sources\n')
	fileOut.write('  file(GLOB sources\n')
	fileOut.write('             src/extension/*.cpp src/extension/*.h\n')
	fileOut.write('             src/sbml/*.cpp src/sbml/*.h \n')
	fileOut.write('             src/common/*.h )\n\n')
	fileOut.write('  # add sources \n')
	fileOut.write('  set(SOURCE_FILES ${sources} )\n\n')	
	fileOut.write('  include_directories(${LIBSBML_SOURCE}/include)\n\n')
	fileOut.write('  find_library(LIBSBML_LIBS \n')
	fileOut.write('    NAMES libsbml.lib sbml\n')
	fileOut.write('    PATHS ${LIBSBML_SOURCE} \n')
	fileOut.write('      ${LIBSBML_SOURCE/lib}\n')
	fileOut.write('      ${LIBSBML_SOURCE/src/.libs}\n')
	fileOut.write('      /usr/lib /usr/local/lib \n')
	fileOut.write('      ${LIBSBML_ROOT_SOURCE_DIR} \n')
	fileOut.write('      ${LIBSBML_ROOT_SOURCE_DIR}/dependencies/lib\n')
	fileOut.write('              )\n\n')
	fileOut.write('  make_directory(${CMAKE_CURRENT_BINARY_DIR}/include/sbml/')
	fileOut.write('{0})\n\n'.format(name))
	fileOut.write('  # copy header files to facilitate build\n')
	fileOut.write('  foreach(dir common extension sbml validator validator/constraints)\n\n')
	fileOut.write('    # copy files\n')
	fileOut.write('    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/${dir}/\n')
	fileOut.write('         DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/sbml/')
	fileOut.write('{0}\n'.format(name))
	fileOut.write('         PATTERN ${CMAKE_CURRENT_SOURCE_DIR}/src/${dir}/*.h)\n\n')
	fileOut.write('  endforeach()\n\n')
	fileOut.write('  if (NOT UNIX)\n')
	fileOut.write('    add_definitions(-DWIN32 -DLIBSBML_EXPORTS -DLIBLAX_EXPORTS)\n')
	fileOut.write('  endif()\n\n')
	fileOut.write('  include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)\n')
	fileOut.write('  include_directories("src/common")\n')
	fileOut.write('  include_directories("src/extension")\n')
	fileOut.write('  include_directories("src/sbml")\n\n')
	fileOut.write('  add_library({0} STATIC '.format(name))
	fileOut.write('${SOURCE_FILES} )\n')
	fileOut.write('  target_link_libraries({0} '.format(name))
	fileOut.write('${LIBSBML_LIBS})\n\n')
	fileOut.write('  option(WITH_EXAMPLE "Compile Example File" ON)\n\n')
	fileOut.write('  if(WITH_EXAMPLE)\n\n')		
	fileOut.write('    set(EXAMPLE_SOURCE examples/c++/example1.cpp)\n')
	fileOut.write('    add_executable({0}_example '.format(name))
	fileOut.write('${EXAMPLE_SOURCE})\n')
	fileOut.write('    target_link_libraries({0}_example {0} '.format(name))
	fileOut.write('${EXTRA_LIBS})\n\n')
	fileOut.write('  endif()\n\n')
	fileOut.write('else()\n')
	fileOut.write('  add_subdirectory(src)\n')
	fileOut.write('endif()\n')

	
	

def writeSrcFile(name):
	capName = name.upper()
	codeName = name + '-package.cmake'
	fileOut = open(codeName, 'w')
	fileHeaders.addCMakeFilename(fileOut, codeName, name)
	fileHeaders.addCMakeLicence(fileOut)
	fileOut.write('\n')
	fileOut.write('if (ENABLE_{0} )\n\n'.format(capName))
	fileOut.write('include(${LIBSBML_ROOT_SOURCE_DIR}/')
	fileOut.write('{0}-package.cmake)\n\n'.format(name))
	fileOut.write('#build up sources\n')
	fileOut.write('set({0}_SOURCES)\n\n'.format(capName))
	fileOut.write('# go through all directories: common, extension and sbml\n')
	fileOut.write('foreach(dir common extension sbml validator validator/constraints)\n\n')
	fileOut.write('  # add to include directory\n')
	fileOut.write('  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sbml/packages/')
	fileOut.write('{0}/$'.format(name))
	fileOut.write('{dir})\n\n')
	fileOut.write('  # file sources\n')
	fileOut.write('  file(GLOB current ${CMAKE_CURRENT_SOURCE_DIR}/sbml/packages/')
	fileOut.write('{0}/$'.format(name))
	fileOut.write('{dir}/*.cpp\n')
	fileOut.write('                    ${CMAKE_CURRENT_SOURCE_DIR}/sbml/packages/')
	fileOut.write('{0}/$'.format(name))
	fileOut.write('{dir}/*.c\n')
	fileOut.write('                    ${CMAKE_CURRENT_SOURCE_DIR}/sbml/packages/')
	fileOut.write('{0}/$'.format(name))
	fileOut.write('{dir}/*.h)\n\n')
	fileOut.write('  # add sources\n')
	fileOut.write('  set({0}_SOURCES $'.format(capName))
	fileOut.write('{')
	fileOut.write('{0}_SOURCES'.format(capName))
	fileOut.write('} ${current})\n\n')
	fileOut.write('  # mark header files for installation\n')
	fileOut.write('  file(GLOB {0}_headers\n'.format(name))
	fileOut.write('                    ${CMAKE_CURRENT_SOURCE_DIR}/sbml/packages/')
	fileOut.write('{0}/$'.format(name))
	fileOut.write('{dir}/*.h)\n\n')
	fileOut.write('  install(FILES  ${')
	fileOut.write('{0}_headers'.format(name))
	fileOut.write('}\n                    DESTINATION include/sbml/packages/')
	fileOut.write('{0}/$'.format(name))
	fileOut.write('{dir} )\n\n')
	fileOut.write('endforeach()\n\n')
	fileOut.write('# create source group for IDEs\n')
	fileOut.write('source_group({0}_package FILES $'.format(name))
	fileOut.write('{')
	fileOut.write('{0}_SOURCES'.format(capName))
	fileOut.write('})\n\n')
	fileOut.write('# add {0} sources to SBML sources\n'.format(name))
	fileOut.write('SET(LIBSBML_SOURCES ${LIBSBML_SOURCES} ${')
	fileOut.write('{0}_SOURCES'.format(capName))
	fileOut.write('})\n\n')
	fileOut.write('######################################################\n')
	fileOut.write('#\n# add test scripts\n#\n')
	fileOut.write('if(WITH_CHECK)\n\n\n')
	fileOut.write('endif()\n\n')
	fileOut.write('endif()\n\n')
	
	
def writeTopLevelFile(name):
	capName = name.upper()
	codeName = name + '-package.cmake'
	fileOut = open(codeName, 'w')
	fileHeaders.addCMakeFilename(fileOut, codeName, name)
	fileHeaders.addCMakeLicence(fileOut)
	fileOut.write('\n')
	fileOut.write('option(ENABLE_{0}        "Enable libSBML support for the \'{1}\' package"      OFF)\n\n\n'.format(capName, name))
	fileOut.write('\n')
	fileOut.write('# provide summary status                                    =\n')
	fileOut.write('list(APPEND LIBSBML_PACKAGE_SUMMARY "SBML \'{0}\' package    = $'.format(name))
	fileOut.write('{')
	fileOut.write('ENABLE_{0}'.format(capName))
	fileOut.write('}")\n')
	fileOut.write('\n')
	fileOut.write('if (ENABLE_{0} )\n'.format(capName))
	fileOut.write('  add_definitions(-DUSE_{0})\n'.format(capName))
	fileOut.write('  set(LIBSBML_PACKAGE_INCLUDES ${LIBSBML_PACKAGE_INCLUDES} ')
	fileOut.write('"LIBSBML_HAS_PACKAGE_{0}")\n'.format(capName))
	fileOut.write('  list(APPEND SWIG_EXTRA_ARGS -DUSE_{0})\n'.format(capName))
	fileOut.write('  list(APPEND SWIG_SWIGDOCDEFINES --define USE_{0})\n'.format(capName))
	fileOut.write('endif()\n\n')
	
def main(package):
	nameOfPackage = package['name']
	name = nameOfPackage.lower()
	plugins = package['plugins']
	classes = package['sbmlElements']
	os.chdir('./' + name)
	writeTopLevelFile(name)
#	writeTopLevelListsFile(name)
	os.chdir('./src')
	writeSrcFile(name)
#	writeSrcListsFile(name, nameOfPackage, plugins, classes)
