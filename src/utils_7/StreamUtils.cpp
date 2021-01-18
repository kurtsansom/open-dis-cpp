#include <utils_7/StreamUtils.h>

#include <dis7/EntityStatePdu.h>
#include <dis7/EntityID.h>
#include <dis7/DetonationPdu.h>

std::ostream& operator <<(std::ostream& lhs, const DIS::EntityType& rhs)
{
   lhs << "EntityType ("
       << (unsigned int)rhs.getEntityKind()
       << "," << (unsigned int)rhs.getDomain()
       << "," << (unsigned int)rhs.getCountry()
       << "," << (unsigned int)rhs.getCategory()
       << "," << (unsigned int)rhs.getSubcategory()
       << ") ";
   return lhs;
}

std::ostream& operator <<(std::ostream& lhs, const DIS::EntityID& rhs)
{
   lhs << "EntityID ("
       << (unsigned int)rhs.getEntity() << ") ";
   return lhs;
}

std::ostream& operator <<(std::ostream& lhs, const DIS::EntityStatePdu& rhs)
{
   lhs << "EntityStatePdu (" << rhs.getEntityID() << ") ";
   return lhs;
}

std::ostream& operator <<(std::ostream& lhs, const DIS::DetonationPdu& rhs)
{
   lhs << "DetonationPDU (" << rhs.getFiringEntityID() << ") ";
   return lhs;
}
