/**
 * @file SpatialReactionPlugin.h
 * @brief Definition of the SpatialReactionPlugin class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SpatialReactionPlugin
 * @sbmlbrief{spatial} Extension of Reaction.
 */


#ifndef SpatialReactionPlugin_H__
#define SpatialReactionPlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/spatial/extension/SpatialExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN SpatialReactionPlugin : public SBasePlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  bool mIsLocal;
  bool mIsSetIsLocal;

  /** @endcond */

public:

  /**
   * Creates a new SpatialReactionPlugin using the given uri, prefix and
   * package namespace.
   *
   * @param uri a string, representing the uri of the package.
   *
   * @param prefix a string, the prefix to be used.
   *
   * @param spatialns a pointer to the SpatialPkgNamespaces object to be used.
   */
  SpatialReactionPlugin(const std::string& uri,
                        const std::string& prefix,
                        SpatialPkgNamespaces* spatialns);


  /**
   * Copy constructor for SpatialReactionPlugin.
   *
   * @param orig the SpatialReactionPlugin instance to copy.
   */
  SpatialReactionPlugin(const SpatialReactionPlugin& orig);


  /**
   * Assignment operator for SpatialReactionPlugin.
   *
   * @param rhs the SpatialReactionPlugin object whose values are to be used as
   * the basis of the assignment.
   */
  SpatialReactionPlugin& operator=(const SpatialReactionPlugin& rhs);


  /**
   * Creates and returns a deep copy of this SpatialReactionPlugin object.
   *
   * @return a (deep) copy of this SpatialReactionPlugin object.
   */
  virtual SpatialReactionPlugin* clone() const;


  /**
   * Destructor for SpatialReactionPlugin.
   */
  virtual ~SpatialReactionPlugin();


  /**
   * Returns the value of the "isLocal" attribute of this
   * SpatialReactionPlugin.
   *
   * @return the value of the "isLocal" attribute of this SpatialReactionPlugin
   * as a boolean.
   */
  bool getIsLocal() const;


  /**
   * Predicate returning @c true if this SpatialReactionPlugin's "isLocal"
   * attribute is set.
   *
   * @return @c true if this SpatialReactionPlugin's "isLocal" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetIsLocal() const;


  /**
   * Sets the value of the "isLocal" attribute of this SpatialReactionPlugin.
   *
   * @param isLocal bool value of the "isLocal" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setIsLocal(bool isLocal);


  /**
   * Unsets the value of the "isLocal" attribute of this SpatialReactionPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetIsLocal();


  /**
   * Predicate returning @c true if all the required attributes for this
   * SpatialReactionPlugin object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SpatialReactionPlugin have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SpatialReactionPlugin object are:
   * @li "isLocal"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#endif /* !SpatialReactionPlugin_H__ */


