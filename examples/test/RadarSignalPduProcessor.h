#ifndef _example_entity_state_pdu_processor_h_
#define _example_entity_state_pdu_processor_h_

#include "RadarSignalPdu.h"                  // for typedef
#include <common/IPacketProcessor.h>         // for base class

namespace Example
{
   class RadarSignalPduProcessor : public DIS::IPacketProcessor
   {
   public:
      typedef DIS::RadarSignalPdu PduType;

      void Process(const DIS::Pdu& packet);
   };
}

#endif  // _example_entity_state_pdu_processor_h_
