/**
 * @file SpatialReactionPlugin.cpp
 * @brief Implementation of the SpatialReactionPlugin class.
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
 */
#include <sbml/packages/spatial/extension/SpatialReactionPlugin.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SpatialReactionPlugin using the given uri, prefix and package
 * namespace.
 */
SpatialReactionPlugin::SpatialReactionPlugin(const std::string& uri,
                                             const std::string& prefix,
                                             SpatialPkgNamespaces* spatialns)
  : SBasePlugin(uri, prefix, spatialns)
  , mIsLocal (false)
  , mIsSetIsLocal (false)
{
}


/*
 * Copy constructor for SpatialReactionPlugin.
 */
SpatialReactionPlugin::SpatialReactionPlugin(const SpatialReactionPlugin& orig)
  : SBasePlugin( orig )
  , mIsLocal ( orig.mIsLocal )
  , mIsSetIsLocal ( orig.mIsSetIsLocal )
{
}


/*
 * Assignment operator for SpatialReactionPlugin.
 */
SpatialReactionPlugin&
SpatialReactionPlugin::operator=(const SpatialReactionPlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    mIsLocal = rhs.mIsLocal;
    mIsSetIsLocal = rhs.mIsSetIsLocal;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SpatialReactionPlugin object.
 */
SpatialReactionPlugin*
SpatialReactionPlugin::clone() const
{
  return new SpatialReactionPlugin(*this);
}


/*
 * Destructor for SpatialReactionPlugin.
 */
SpatialReactionPlugin::~SpatialReactionPlugin()
{
}


/*
 * Returns the value of the "isLocal" attribute of this SpatialReactionPlugin.
 */
bool
SpatialReactionPlugin::getIsLocal() const
{
  return mIsLocal;
}


/*
 * Predicate returning @c true if this SpatialReactionPlugin's "isLocal"
 * attribute is set.
 */
bool
SpatialReactionPlugin::isSetIsLocal() const
{
  return mIsSetIsLocal;
}


/*
 * Sets the value of the "isLocal" attribute of this SpatialReactionPlugin.
 */
int
SpatialReactionPlugin::setIsLocal(bool isLocal)
{
  mIsLocal = isLocal;
  mIsSetIsLocal = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "isLocal" attribute of this SpatialReactionPlugin.
 */
int
SpatialReactionPlugin::unsetIsLocal()
{
  mIsLocal = false;
  mIsSetIsLocal = false;

  if (isSetIsLocal() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SpatialReactionPlugin object have been set.
 */
bool
SpatialReactionPlugin::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetIsLocal() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
SpatialReactionPlugin::writeElements(XMLOutputStream& stream) const
{
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
SpatialReactionPlugin::accept(SBMLVisitor& v) const
{
  const Reaction* r = static_cast<const
    Reaction*>(this->getParentSBMLObject());
  v.visit(*r);
  v.leave(*r);

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
SpatialReactionPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
SpatialReactionPlugin::enablePackageInternal(const std::string& pkgURI,
                                             const std::string& pkgPrefix,
                                             bool flag)
{
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
SpatialReactionPlugin::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBasePlugin::addExpectedAttributes(attributes);

  attributes.add("isLocal");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SpatialReactionPlugin::readAttributes(const XMLAttributes& attributes,
                                      const ExpectedAttributes&
                                        expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBasePlugin::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("spatial", SpatialReactionAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("spatial", SpatialReactionAllowedAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // isLocal bool (use = "required" )
  // 

  mIsSetIsLocal = attributes.readInto("isLocal", mIsLocal);

  if (!mIsSetIsLocal)
  {
    std::string message = "Spatial attribute 'isLocal' is missing from the "
      "<SpatialReactionPlugin> element.";
    log->logPackageError("spatial",
      SpatialSpatialReactionPluginAllowedAttributes, pkgVersion, level, version,
        message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
SpatialReactionPlugin::writeAttributes(XMLOutputStream& stream) const
{
  SBasePlugin::writeAttributes(stream);

  if (isSetIsLocal() == true)
  {
    stream.writeAttribute("isLocal", getPrefix(), mIsLocal);
  }
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


