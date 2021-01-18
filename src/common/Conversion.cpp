#include <common/Conversion.h>
#include <common/Masks.h>


int DIS::Convert::MakeArticulationParameterType(int typeclass, int typemetric)
{
   // enforce a ceiling on typemetric
   typemetric = typemetric & DIS::ARTICULATION_PARAMETER_TYPE_METRIC_MASK;

   // shift the typeclass bits to the left by the precision amount of typemetric
   // and then add the typemetric bits
   return( (typeclass << ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS)
          + typemetric );
}

int DIS::Convert::GetArticulationTypeMetric(int parametertype)
{
   // wipe off the typeclass bits and return the typemetric bits
   return( parametertype & DIS::ARTICULATION_PARAMETER_TYPE_METRIC_MASK);
}

int DIS::Convert::GetArticulationTypeClass(int parametertype)
{
   // wipe off the typemetric bits and return the typeclass bits
   return( parametertype >> ARTICULATION_PARAMETER_TYPE_METRIC_NUMBER_OF_BITS );
}
