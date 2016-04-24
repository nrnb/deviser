/**
 * @file SedVisitor.cpp
 * @brief Implementation of the SedVisitor class.
 * @author DEVISER
 */



#include <sedml/SedVisitor.h>
#include <sedml/SedTypes.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SedVisitor::~SedVisitor ()
{
}


void
SedVisitor::visit (const SedDocument& x)
{
  visit( static_cast<const SedBase&>(x) );
}


void
SedVisitor::visit (const SedListOf& x, int type)
{
  visit( static_cast<const SedBase&>(x) );
}


bool
SedVisitor::visit (const SedBase& sb)
{
  return false;
}


/*
 * Visit the SedModel
 */
bool
SedVisitor::visit(const SedModel& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedChange
 */
bool
SedVisitor::visit(const SedChange& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedAddXML
 */
bool
SedVisitor::visit(const SedAddXML& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSetValue
 */
bool
SedVisitor::visit(const SedSetValue& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedDataGenerator
 */
bool
SedVisitor::visit(const SedDataGenerator& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedRepeatedTask
 */
bool
SedVisitor::visit(const SedRepeatedTask& x)
{
  return visit(static_cast<const SedBase&>(x));
}


/*
 * Visit the SedSimulation
 */
bool
SedVisitor::visit(const SedSimulation& x)
{
  return visit(static_cast<const SedBase&>(x));
}


void
SedVisitor::leave (const SedDocument& x)
{
}


void
SedVisitor::leave (const SedBase& sb)
{
}


void
SedVisitor::leave (const SedListOf& x, int type)
{
}


/*
 * Leave the SedModel
 */
void
SedVisitor::leave(const SedModel& x)
{
}


/*
 * Leave the SedChange
 */
void
SedVisitor::leave(const SedChange& x)
{
}


/*
 * Leave the SedAddXML
 */
void
SedVisitor::leave(const SedAddXML& x)
{
}


/*
 * Leave the SedSetValue
 */
void
SedVisitor::leave(const SedSetValue& x)
{
}


/*
 * Leave the SedDataGenerator
 */
void
SedVisitor::leave(const SedDataGenerator& x)
{
}


/*
 * Leave the SedRepeatedTask
 */
void
SedVisitor::leave(const SedRepeatedTask& x)
{
}


/*
 * Leave the SedSimulation
 */
void
SedVisitor::leave(const SedSimulation& x)
{
}



#endif /* __cplusplus */


LIBSEDML_CPP_NAMESPACE_END