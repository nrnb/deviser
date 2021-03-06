/**
 * @file Boundary.cpp
 * @brief Implementation of the Boundary class.
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
#include <sbml/packages/spatial/sbml/Boundary.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Boundary using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 */
Boundary::Boundary(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mValue (util_NaN())
  , mIsSetValue (false)
  , mElementName("boundary")
{
  setSBMLNamespacesAndOwn(new SpatialPkgNamespaces(level, version,
    pkgVersion));
}


/*
 * Creates a new Boundary using the given SpatialPkgNamespaces object.
 */
Boundary::Boundary(SpatialPkgNamespaces *spatialns)
  : SBase(spatialns)
  , mId ("")
  , mValue (util_NaN())
  , mIsSetValue (false)
  , mElementName("boundary")
{
  setElementNamespace(spatialns->getURI());
  loadPlugins(spatialns);
}


/*
 * Copy constructor for Boundary.
 */
Boundary::Boundary(const Boundary& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mValue ( orig.mValue )
  , mIsSetValue ( orig.mIsSetValue )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for Boundary.
 */
Boundary&
Boundary::operator=(const Boundary& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mValue = rhs.mValue;
    mIsSetValue = rhs.mIsSetValue;
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Boundary object.
 */
Boundary*
Boundary::clone() const
{
  return new Boundary(*this);
}


/*
 * Destructor for Boundary.
 */
Boundary::~Boundary()
{
}


/*
 * Returns the value of the "id" attribute of this Boundary.
 */
const std::string&
Boundary::getId() const
{
  return mId;
}


/*
 * Returns the value of the "value" attribute of this Boundary.
 */
double
Boundary::getValue() const
{
  return mValue;
}


/*
 * Predicate returning @c true if this Boundary's "id" attribute is set.
 */
bool
Boundary::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Boundary's "value" attribute is set.
 */
bool
Boundary::isSetValue() const
{
  return mIsSetValue;
}


/*
 * Sets the value of the "id" attribute of this Boundary.
 */
int
Boundary::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "value" attribute of this Boundary.
 */
int
Boundary::setValue(double value)
{
  mValue = value;
  mIsSetValue = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Boundary.
 */
int
Boundary::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "value" attribute of this Boundary.
 */
int
Boundary::unsetValue()
{
  mValue = util_NaN();
  mIsSetValue = false;

  if (isSetValue() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this Boundary object.
 */
const std::string&
Boundary::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the XML name of this Boundary object.
 */
void
Boundary::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBML type code for this Boundary object.
 */
int
Boundary::getTypeCode() const
{
  return SBML_SPATIAL_BOUNDARY;
}


/*
 * Predicate returning @c true if all the required attributes for this Boundary
 * object have been set.
 */
bool
Boundary::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetValue() == false)
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
Boundary::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Boundary::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Boundary::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Boundary::enablePackageInternal(const std::string& pkgURI,
                                const std::string& pkgPrefix,
                                bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Boundary::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("value");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Boundary::readAttributes(const XMLAttributes& attributes,
                         const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("spatial", SpatialBoundaryAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("spatial", SpatialBoundaryAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<Boundary>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SpatialIdSyntaxRule, level, version, "The id '" + mId + "' does "
        "not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Spatial attribute 'id' is missing from the "
      "<Boundary> element.";
    log->logPackageError("spatial", SpatialBoundaryAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // value double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetValue = attributes.readInto("value", mValue);

  if ( mIsSetValue == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Spatial attribute 'value' from the <Boundary> "
        "element must be an integer.";
      log->logPackageError("spatial", SpatialBoundaryValueMustBeDouble,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Spatial attribute 'value' is missing from the "
        "<Boundary> element.";
      log->logPackageError("spatial", SpatialBoundaryAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Boundary::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetValue() == true)
  {
    stream.writeAttribute("value", getPrefix(), mValue);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Boundary_t using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 */
LIBSBML_EXTERN
Boundary_t *
Boundary_create(unsigned int level,
                unsigned int version,
                unsigned int pkgVersion)
{
  return new Boundary(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Boundary_t object.
 */
LIBSBML_EXTERN
Boundary_t*
Boundary_clone(const Boundary_t* b)
{
  if (b != NULL)
  {
    return static_cast<Boundary_t*>(b->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Boundary_t object.
 */
LIBSBML_EXTERN
void
Boundary_free(Boundary_t* b)
{
  if (b != NULL)
  {
    delete b;
  }
}


/*
 * Returns the value of the "id" attribute of this Boundary_t.
 */
LIBSBML_EXTERN
const char *
Boundary_getId(const Boundary_t * b)
{
  if (b == NULL)
  {
    return NULL;
  }

  return b->getId().empty() ? NULL : safe_strdup(b->getId().c_str());
}


/*
 * Returns the value of the "value" attribute of this Boundary_t.
 */
LIBSBML_EXTERN
double
Boundary_getValue(const Boundary_t * b)
{
  return (b != NULL) ? b->getValue() : util_NaN();
}


/*
 * Predicate returning @c 1 if this Boundary_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
Boundary_isSetId(const Boundary_t * b)
{
  return (b != NULL) ? static_cast<int>(b->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this Boundary_t's "value" attribute is set.
 */
LIBSBML_EXTERN
int
Boundary_isSetValue(const Boundary_t * b)
{
  return (b != NULL) ? static_cast<int>(b->isSetValue()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Boundary_t.
 */
LIBSBML_EXTERN
int
Boundary_setId(Boundary_t * b, const char * id)
{
  return (b != NULL) ? b->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "value" attribute of this Boundary_t.
 */
LIBSBML_EXTERN
int
Boundary_setValue(Boundary_t * b, double value)
{
  return (b != NULL) ? b->setValue(value) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Boundary_t.
 */
LIBSBML_EXTERN
int
Boundary_unsetId(Boundary_t * b)
{
  return (b != NULL) ? b->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "value" attribute of this Boundary_t.
 */
LIBSBML_EXTERN
int
Boundary_unsetValue(Boundary_t * b)
{
  return (b != NULL) ? b->unsetValue() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this Boundary_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Boundary_hasRequiredAttributes(const Boundary_t * b)
{
  return (b != NULL) ? static_cast<int>(b->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


