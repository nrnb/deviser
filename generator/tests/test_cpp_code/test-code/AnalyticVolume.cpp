/**
 * @file AnalyticVolume.cpp
 * @brief Implementation of the AnalyticVolume class.
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
#include <sbml/packages/spatial/sbml/AnalyticVolume.h>
#include <sbml/packages/spatial/sbml/ListOfAnalyticVolumes.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new AnalyticVolume using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 */
AnalyticVolume::AnalyticVolume(unsigned int level,
                               unsigned int version,
                               unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mFunctionType (FUNCTION_KIND_INVALID)
  , mOrdinal (SBML_INT_MAX)
  , mIsSetOrdinal (false)
  , mDomainType ("")
  , mMath (NULL)
{
  setSBMLNamespacesAndOwn(new SpatialPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new AnalyticVolume using the given SpatialPkgNamespaces object.
 */
AnalyticVolume::AnalyticVolume(SpatialPkgNamespaces *spatialns)
  : SBase(spatialns)
  , mId ("")
  , mFunctionType (FUNCTION_KIND_INVALID)
  , mOrdinal (SBML_INT_MAX)
  , mIsSetOrdinal (false)
  , mDomainType ("")
  , mMath (NULL)
{
  setElementNamespace(spatialns->getURI());
  connectToChild();
  loadPlugins(spatialns);
}


/*
 * Copy constructor for AnalyticVolume.
 */
AnalyticVolume::AnalyticVolume(const AnalyticVolume& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mFunctionType ( orig.mFunctionType )
  , mOrdinal ( orig.mOrdinal )
  , mIsSetOrdinal ( orig.mIsSetOrdinal )
  , mDomainType ( orig.mDomainType )
  , mMath ( NULL )
{
  if (orig.mMath != NULL)
  {
    mMath = orig.mMath->deepCopy();
  }

  connectToChild();
}


/*
 * Assignment operator for AnalyticVolume.
 */
AnalyticVolume&
AnalyticVolume::operator=(const AnalyticVolume& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mFunctionType = rhs.mFunctionType;
    mOrdinal = rhs.mOrdinal;
    mIsSetOrdinal = rhs.mIsSetOrdinal;
    mDomainType = rhs.mDomainType;
    delete mMath;
    if (rhs.mMath != NULL)
    {
      mMath = rhs.mMath->deepCopy();
    }
    else
    {
      mMath = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this AnalyticVolume object.
 */
AnalyticVolume*
AnalyticVolume::clone() const
{
  return new AnalyticVolume(*this);
}


/*
 * Destructor for AnalyticVolume.
 */
AnalyticVolume::~AnalyticVolume()
{
  delete mMath;
  mMath = NULL;
}


/*
 * Returns the value of the "id" attribute of this AnalyticVolume.
 */
const std::string&
AnalyticVolume::getId() const
{
  return mId;
}


/*
 * Returns the value of the "functionType" attribute of this AnalyticVolume.
 */
FunctionKind_t
AnalyticVolume::getFunctionType() const
{
  return mFunctionType;
}


/*
 * Returns the value of the "functionType" attribute of this AnalyticVolume.
 */
const std::string&
AnalyticVolume::getFunctionTypeAsString() const
{
  static const std::string code_str = FunctionKind_toString(mFunctionType);
  return code_str;
}


/*
 * Returns the value of the "ordinal" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::getOrdinal() const
{
  return mOrdinal;
}


/*
 * Returns the value of the "domainType" attribute of this AnalyticVolume.
 */
const std::string&
AnalyticVolume::getDomainType() const
{
  return mDomainType;
}


/*
 * Predicate returning @c true if this AnalyticVolume's "id" attribute is set.
 */
bool
AnalyticVolume::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this AnalyticVolume's "functionType"
 * attribute is set.
 */
bool
AnalyticVolume::isSetFunctionType() const
{
  return (mFunctionType != FUNCTION_KIND_INVALID);
}


/*
 * Predicate returning @c true if this AnalyticVolume's "ordinal" attribute is
 * set.
 */
bool
AnalyticVolume::isSetOrdinal() const
{
  return mIsSetOrdinal;
}


/*
 * Predicate returning @c true if this AnalyticVolume's "domainType" attribute
 * is set.
 */
bool
AnalyticVolume::isSetDomainType() const
{
  return (mDomainType.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "functionType" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::setFunctionType(const FunctionKind_t functionType)
{
  if (FunctionKind_isValid(functionType) == 0)
  {
    mFunctionType = FUNCTION_KIND_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mFunctionType = functionType;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "functionType" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::setFunctionType(const std::string& functionType)
{
  if (FunctionKind_isValidString(functionType.c_str()) == 0)
  {
    mFunctionType = FUNCTION_KIND_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mFunctionType = FunctionKind_fromString(functionType.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "ordinal" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::setOrdinal(int ordinal)
{
  mOrdinal = ordinal;
  mIsSetOrdinal = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "domainType" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::setDomainType(const std::string& domainType)
{
  if (!(SyntaxChecker::isValidInternalSId(domainType)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mDomainType = domainType;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::unsetId()
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
 * Unsets the value of the "functionType" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::unsetFunctionType()
{
  mFunctionType = FUNCTION_KIND_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "ordinal" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::unsetOrdinal()
{
  mOrdinal = SBML_INT_MAX;
  mIsSetOrdinal = false;

  if (isSetOrdinal() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "domainType" attribute of this AnalyticVolume.
 */
int
AnalyticVolume::unsetDomainType()
{
  mDomainType.erase();

  if (mDomainType.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "math" element of this AnalyticVolume.
 */
const ASTNode*
AnalyticVolume::getMath() const
{
  return mMath;
}


/*
 * Returns the value of the "math" element of this AnalyticVolume.
 */
ASTNode*
AnalyticVolume::getMath()
{
  return mMath;
}


/*
 * Predicate returning @c true if this AnalyticVolume's "math" element is set.
 */
bool
AnalyticVolume::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Sets the value of the "math" element of this AnalyticVolume.
 */
int
AnalyticVolume::setMath(const ASTNode* math)
{
  if (mMath == math)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (math == NULL)
  {
    delete mMath;
    mMath = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (!(math->isWellFormedASTNode()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else
  {
    delete mMath;
    mMath = (math != NULL) ? math->deepCopy() : NULL;
    if (mMath != NULL)
    {
      mMath->setParentSBMLObject(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "math" element of this AnalyticVolume.
 */
int
AnalyticVolume::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
AnalyticVolume::renameSIdRefs(const std::string& oldid,
                              const std::string& newid)
{
  if (isSetDomainType() && mDomainType == oldid)
  {
    setDomainType(newid);
  }

  if (isSetMath())
  {
    mMath->renameSIdRefs(oldid, newid);
  }
}


/*
 * Returns the XML element name of this AnalyticVolume object.
 */
const std::string&
AnalyticVolume::getElementName() const
{
  static const string name = "analyticVolume";
  return name;
}


/*
 * Returns the libSBML type code for this AnalyticVolume object.
 */
int
AnalyticVolume::getTypeCode() const
{
  return SBML_SPATIAL_ANALYTICVOLUME;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * AnalyticVolume object have been set.
 */
bool
AnalyticVolume::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetFunctionType() == false)
  {
    allPresent = false;
  }

  if (isSetDomainType() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * AnalyticVolume object have been set.
 */
bool
AnalyticVolume::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
AnalyticVolume::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetMath() == true)
  {
    writeMathML(getMath(), stream, getSBMLNamespaces());
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
AnalyticVolume::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
AnalyticVolume::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
AnalyticVolume::connectToChild()
{
  SBase::connectToChild();
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
AnalyticVolume::enablePackageInternal(const std::string& pkgURI,
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
AnalyticVolume::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("functionType");

  attributes.add("ordinal");

  attributes.add("domainType");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
AnalyticVolume::readAttributes(const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<ListOfAnalyticVolumes*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("spatial",
          SpatialAnalyticGeometryLOAnalyticVolumesAllowedAttributes, pkgVersion,
            level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("spatial",
          SpatialAnalyticGeometryLOAnalyticVolumesAllowedCoreAttributes,
            pkgVersion, level, version, details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("spatial", SpatialAnalyticVolumeAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("spatial",
        SpatialAnalyticVolumeAllowedCoreAttributes, pkgVersion, level, version,
          details);
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
      logEmptyString(mId, level, version, "<AnalyticVolume>");
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
      "<AnalyticVolume> element.";
    log->logPackageError("spatial", SpatialAnalyticVolumeAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // functionType enum (use = "required" )
  // 

  std::string functiontype;
  assigned = attributes.readInto("functionType", functiontype);

  if (assigned == true)
  {
    if (functiontype.empty() == true)
    {
      logEmptyString(functiontype, level, version, "<AnalyticVolume>");
    }
    else
    {
      mFunctionType = FunctionKind_fromString(functiontype.c_str());

      if (FunctionKind_isValid(mFunctionType) == 0)
      {
        std::string msg = "The functionType on the <AnalyticVolume> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + functiontype + "', which is not a valid option.";

        log->logPackageError("spatial",
          SpatialAnalyticVolumeFunctionTypeMustBeFunctionKindEnum, pkgVersion,
            level, version, msg);
      }
    }
  }
  else
  {
    std::string message = "Spatial attribute 'functionType' is missing.";
    log->logPackageError("spatial", SpatialAnalyticVolumeAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // ordinal int (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetOrdinal = attributes.readInto("ordinal", mOrdinal);

  if ( mIsSetOrdinal == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Spatial attribute 'ordinal' from the "
        "<AnalyticVolume> element must be an integer.";
      log->logPackageError("spatial",
        SpatialAnalyticVolumeOrdinalMustBeInteger, pkgVersion, level, version,
          message);
    }
  }

  // 
  // domainType SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("domainType", mDomainType);

  if (assigned == true)
  {
    if (mDomainType.empty() == true)
    {
      logEmptyString(mDomainType, level, version, "<AnalyticVolume>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mDomainType) == false)
    {
      logError(SpatialAnalyticVolumeDomainTypeMustBeDomainType, level, version,
        "The attribute domainType='" + mDomainType + "' does not conform to the "
          "syntax.");
    }
  }
  else
  {
    std::string message = "Spatial attribute 'domainType' is missing from the "
      "<AnalyticVolume> element.";
    log->logPackageError("spatial", SpatialAnalyticVolumeAllowedAttributes,
      pkgVersion, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
AnalyticVolume::readOtherXML(XMLInputStream& stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "math")
  {
    const XMLToken elem = stream.peek();
    const std::string prefix = checkMathMLNamespace(elem);
    if (stream.getSBMLNamespaces() == NULL)
    {
      stream.setSBMLNamespaces(new SBMLNamespaces(getLevel(), getVersion()));
    }

    delete mMath;
    mMath = readMathML(stream, prefix);
    read = true;
  }

  if (SBase::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
AnalyticVolume::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetFunctionType() == true)
  {
    stream.writeAttribute("functionType", getPrefix(),
      FunctionKind_toString(mFunctionType));
  }

  if (isSetOrdinal() == true)
  {
    stream.writeAttribute("ordinal", getPrefix(), mOrdinal);
  }

  if (isSetDomainType() == true)
  {
    stream.writeAttribute("domainType", getPrefix(), mDomainType);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new AnalyticVolume_t using the given SBML Level, Version and
 * &ldquo;spatial&rdquo; package version.
 */
LIBSBML_EXTERN
AnalyticVolume_t *
AnalyticVolume_create(unsigned int level,
                      unsigned int version,
                      unsigned int pkgVersion)
{
  return new AnalyticVolume(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this AnalyticVolume_t object.
 */
LIBSBML_EXTERN
AnalyticVolume_t*
AnalyticVolume_clone(const AnalyticVolume_t* av)
{
  if (av != NULL)
  {
    return static_cast<AnalyticVolume_t*>(av->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this AnalyticVolume_t object.
 */
LIBSBML_EXTERN
void
AnalyticVolume_free(AnalyticVolume_t* av)
{
  if (av != NULL)
  {
    delete av;
  }
}


/*
 * Returns the value of the "id" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
const char *
AnalyticVolume_getId(const AnalyticVolume_t * av)
{
  if (av == NULL)
  {
    return NULL;
  }

  return av->getId().empty() ? NULL : safe_strdup(av->getId().c_str());
}


/*
 * Returns the value of the "functionType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
FunctionKind_t
AnalyticVolume_getFunctionType(const AnalyticVolume_t * av)
{
  if (av == NULL)
  {
    return FUNCTION_KIND_INVALID;
  }

  return av->getFunctionType();
}


/*
 * Returns the value of the "functionType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
const char *
AnalyticVolume_getFunctionTypeAsString(const AnalyticVolume_t * av)
{
  return FunctionKind_toString(av->getFunctionType());
}


/*
 * Returns the value of the "ordinal" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_getOrdinal(const AnalyticVolume_t * av)
{
  return (av != NULL) ? av->getOrdinal() : SBML_INT_MAX;
}


/*
 * Returns the value of the "domainType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
const char *
AnalyticVolume_getDomainType(const AnalyticVolume_t * av)
{
  if (av == NULL)
  {
    return NULL;
  }

  return av->getDomainType().empty() ? NULL :
    safe_strdup(av->getDomainType().c_str());
}


/*
 * Predicate returning @c 1 if this AnalyticVolume_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
AnalyticVolume_isSetId(const AnalyticVolume_t * av)
{
  return (av != NULL) ? static_cast<int>(av->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this AnalyticVolume_t's "functionType" attribute
 * is set.
 */
LIBSBML_EXTERN
int
AnalyticVolume_isSetFunctionType(const AnalyticVolume_t * av)
{
  return (av != NULL) ? static_cast<int>(av->isSetFunctionType()) : 0;
}


/*
 * Predicate returning @c 1 if this AnalyticVolume_t's "ordinal" attribute is
 * set.
 */
LIBSBML_EXTERN
int
AnalyticVolume_isSetOrdinal(const AnalyticVolume_t * av)
{
  return (av != NULL) ? static_cast<int>(av->isSetOrdinal()) : 0;
}


/*
 * Predicate returning @c 1 if this AnalyticVolume_t's "domainType" attribute
 * is set.
 */
LIBSBML_EXTERN
int
AnalyticVolume_isSetDomainType(const AnalyticVolume_t * av)
{
  return (av != NULL) ? static_cast<int>(av->isSetDomainType()) : 0;
}


/*
 * Sets the value of the "id" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_setId(AnalyticVolume_t * av, const char * id)
{
  return (av != NULL) ? av->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "functionType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_setFunctionType(AnalyticVolume_t * av,
                               FunctionKind_t functionType)
{
  return (av != NULL) ? av->setFunctionType(functionType) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "functionType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_setFunctionTypeAsString(AnalyticVolume_t * av,
                                       const char * functionType)
{
  return (av != NULL) ? av->setFunctionType(functionType):
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "ordinal" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_setOrdinal(AnalyticVolume_t * av, int ordinal)
{
  return (av != NULL) ? av->setOrdinal(ordinal) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "domainType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_setDomainType(AnalyticVolume_t * av, const char * domainType)
{
  return (av != NULL) ? av->setDomainType(domainType) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_unsetId(AnalyticVolume_t * av)
{
  return (av != NULL) ? av->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "functionType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_unsetFunctionType(AnalyticVolume_t * av)
{
  return (av != NULL) ? av->unsetFunctionType() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "ordinal" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_unsetOrdinal(AnalyticVolume_t * av)
{
  return (av != NULL) ? av->unsetOrdinal() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "domainType" attribute of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_unsetDomainType(AnalyticVolume_t * av)
{
  return (av != NULL) ? av->unsetDomainType() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "math" element of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
const ASTNode_t*
AnalyticVolume_getMath(const AnalyticVolume_t * av)
{
  if (av == NULL)
  {
    return NULL;
  }

  return (ASTNode_t*)(av->getMath());
}


/*
 * Predicate returning @c 1 if this AnalyticVolume_t's "math" element is set.
 */
LIBSBML_EXTERN
int
AnalyticVolume_isSetMath(const AnalyticVolume_t * av)
{
  return (av != NULL) ? static_cast<int>(av->isSetMath()) : 0;
}


/*
 * Sets the value of the "math" element of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_setMath(AnalyticVolume_t * av, const ASTNode_t* math)
{
  return (av != NULL) ? av->setMath(math) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "math" element of this AnalyticVolume_t.
 */
LIBSBML_EXTERN
int
AnalyticVolume_unsetMath(AnalyticVolume_t * av)
{
  return (av != NULL) ? av->unsetMath() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * AnalyticVolume_t object have been set.
 */
LIBSBML_EXTERN
int
AnalyticVolume_hasRequiredAttributes(const AnalyticVolume_t * av)
{
  return (av != NULL) ? static_cast<int>(av->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * AnalyticVolume_t object have been set.
 */
LIBSBML_EXTERN
int
AnalyticVolume_hasRequiredElements(const AnalyticVolume_t * av)
{
  return (av != NULL) ? static_cast<int>(av->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


