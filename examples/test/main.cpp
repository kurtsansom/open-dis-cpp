
#include <iostream>
#include <vector>

// specific for the example
#include "Connection.h"
#include "Utils.h"
#include "Timer.h"

// the DIS library usage
#include "RadarSignalPdu.h"
#include <dis7/OneByteChunk.h>
#include <common/DataStream.h>
#include <common/Conversion.h>



namespace Example
{
   enum SignalEncodingClass
   {
      ENCODED_AUDIO = 0, ///< Encoded audio
      RAW_BINARY_DATA = 1, ///< Raw Binary Data
      APPLICATION_SPECIFIC_DATA = 2, ///< Application-Specific Data
      DATABASE_INDEX = 3, ///< Database index
   };

   enum SignalTDLType
   {
      OTHER = 0, ///< Other
      PADIL = 1, ///< PADIL
      NATO_LINK_1 = 2, ///< NATO Link-1
      ATDL_1 = 3, ///< ATDL-1
      LINK_11B_TADIL_B = 4, ///< Link 11B (TADIL B)
      SITUATIONAL_AWARENESS_DATA_LINK_SADL = 5, ///< Situational Awareness Data Link (SADL)
      LINK_16_LEGACY_FORMAT_JTIDS_TADIL_J = 6, ///< Link 16 Legacy Format (JTIDS/TADIL-J)
      LINK_16_LEGACY_FORMAT_JTIDS_FDL_TADIL_J = 7, ///< Link 16 Legacy Format (JTIDS/FDL/TADIL-J)
      LINK_11A_TADIL_A = 8, ///< Link 11A (TADIL A)
      IJMS = 9, ///< IJMS
      LINK_4A_TADIL_C = 10, ///< Link 4A (TADIL C)
      LINK_4C = 11, ///< Link 4C
      TIBS = 12, ///< TIBS
      ATL = 13, ///< ATL
      CONSTANT_SOURCE = 14, ///< Constant Source
      ABBREVIATED_COMMAND_AND_CONTROL_15 = 15, ///< Abbreviated Command and Control
      MILSTAR = 16, ///< MILSTAR
      ATHS = 17, ///< ATHS
      OTHGOLD = 18, ///< OTHGOLD
      TACELINT = 19, ///< TACELINT
      WEAPONS_DATA_LINK_AWW_13 = 20, ///< Weapons Data Link (AWW-13)
      ENHANCED_POSITION_LOCATION_REPORTING_SYSTEM_EPLRS = 22, ///< Enhanced Position Location Reporting System (EPLRS)
      POSITION_LOCATION_REPORTING_SYSTEM_PLRS = 23, ///< Position Location Reporting System (PLRS)
      SINCGARS = 24, ///< SINCGARS
      HAVE_QUICK_I = 25, ///< Have Quick I
      HAVE_QUICK_II = 26, ///< Have Quick II
      HAVE_QUICK_IIA_SATURN = 27, ///< Have Quick IIA (Saturn)
      INTRA_FLIGHT_DATA_LINK_1 = 28, ///< Intra-Flight Data Link 1
      INTRA_FLIGHT_DATA_LINK_2 = 29, ///< Intra-Flight Data Link 2
      IMPROVED_DATA_MODEM_IDM = 30, ///< Improved Data Modem (IDM)
      AIR_FORCE_APPLICATION_PROGRAM_DEVELOPMENT_AFAPD = 31, ///< Air Force Application Program Development (AFAPD)
      COOPERATIVE_ENGAGEMENT_CAPABILITY_CEC = 32, ///< Cooperative Engagement Capability (CEC)
      FORWARD_AREA_AIR_DEFENSE_FAAD_DATA_LINK_FDL = 33, ///< Forward Area Air Defense (FAAD) Data Link (FDL)
      GROUND_BASED_DATA_LINK_GBDL = 34, ///< Ground Based Data Link (GBDL)
      INTRA_VEHICULAR_INFO_SYSTEM_IVIS = 35, ///< Intra Vehicular Info System (IVIS)
      MARINE_TACTICAL_SYSTEM_MTS = 36, ///< Marine Tactical System (MTS)
      TACTICAL_FIRE_DIRECTION_SYSTEM_TACFIRE = 37, ///< Tactical Fire Direction System (TACFIRE)
      INTEGRATED_BROADCAST_SERVICE_IBS = 38, ///< Integrated Broadcast Service (IBS)
      AIRBORNE_INFORMATION_TRANSFER_ABIT = 39, ///< Airborne Information Transfer (ABIT)
      ADVANCED_TACTICAL_AIRBORNE_RECONNAISSANCE_SYSTEM_ATARS_DATA_LINK = 40, ///< Advanced Tactical Airborne Reconnaissance System (ATARS) Data Link
      BATTLE_GROUP_PASSIVE_HORIZON_EXTENSION_SYSTEM_BGPHES_DATA_LINK = 41, ///< Battle Group Passive Horizon Extension System (BGPHES) Data Link
      COMMON_HIGH_BANDWIDTH_DATA_LINK_CHBDL = 42, ///< Common High Bandwidth Data Link (CHBDL)
      GUARDRAIL_INTEROPERABLE_DATA_LINK_IDL = 43, ///< Guardrail Interoperable Data Link (IDL)
      GUARDRAIL_COMMON_SENSOR_SYSTEM_ONE_CSS1_DATA_LINK = 44, ///< Guardrail Common Sensor System One (CSS1) Data Link
      GUARDRAIL_COMMON_SENSOR_SYSTEM_TWO_CSS2_DATA_LINK = 45, ///< Guardrail Common Sensor System Two (CSS2) Data Link
      GUARDRAIL_CSS2_MULTI_ROLE_DATA_LINK_MRDL = 46, ///< Guardrail CSS2 Multi-Role Data Link (MRDL)
      GUARDRAIL_CSS2_DIRECT_AIR_TO_SATELLITE_RELAY_DASR_DATA_LINK = 47, ///< Guardrail CSS2 Direct Air to Satellite Relay (DASR) Data Link
      LINE_OF_SIGHT_LOS_DATA_LINK_IMPLEMENTATION_LOS_TETHER = 48, ///< Line of Sight (LOS) Data Link Implementation (LOS tether)
      LIGHTWEIGHT_CDL_LWCDL = 49, ///< Lightweight CDL (LWCDL)
      L_52M_SR_71 = 50, ///< L-52M (SR-71)
      RIVET_REACH_RIVET_OWL_DATA_LINK = 51, ///< Rivet Reach/Rivet Owl Data Link
      SENIOR_SPAN = 52, ///< Senior Span
      SENIOR_SPUR = 53, ///< Senior Spur
      SENIOR_STRETCH = 54, ///< Senior Stretch.
      SENIOR_YEAR_INTEROPERABLE_DATA_LINK_IDL = 55, ///< Senior Year Interoperable Data Link (IDL)
      SPACE_CDL = 56, ///< Space CDL
      TR_1_MODE_MIST_AIRBORNE_DATA_LINK = 57, ///< TR-1 mode MIST Airborne Data Link
      KU_BAND_SATCOM_DATA_LINK_IMPLEMENTATION_UAV = 58, ///< Ku-band SATCOM Data Link Implementation (UAV)
      MISSION_EQUIPMENT_CONTROL_DATA_LINK_MECDL = 59, ///< Mission Equipment Control Data link (MECDL)
      RADAR_DATA_TRANSMITTING_SET_DATA_LINK = 60, ///< Radar Data Transmitting Set Data Link
      SURVEILLANCE_AND_CONTROL_DATA_LINK_SCDL = 61, ///< Surveillance and Control Data Link (SCDL)
      TACTICAL_UAV_VIDEO = 62, ///< Tactical UAV Video
      UHF_SATCOM_DATA_LINK_IMPLEMENTATION_UAV = 63, ///< UHF SATCOM Data Link Implementation (UAV)
      TACTICAL_COMMON_DATA_LINK_TCDL = 64, ///< Tactical Common Data Link (TCDL)
      LOW_LEVEL_AIR_PICTURE_INTERFACE_LLAPI = 65, ///< Low Level Air Picture Interface (LLAPI)
      WEAPONS_DATA_LINK_AGM_130 = 66, ///< Weapons Data Link (AGM-130)
      AUTOMATIC_IDENTIFICATION_SYSTEM_AIS = 67, ///< Automatic Identification System (AIS)
      WEAPONS_DATA_LINK_AIM_120 = 68, ///< Weapons Data Link (AIM-120)
      WEAPONS_DATA_LINK_AIM_9 = 69, ///< Weapons Data Link (AIM-9)
      WEAPONS_DATA_LINK_CAMM = 70, ///< Weapons Data Link (CAMM)
      GC3 = 99, ///< GC3
      LINK_16_STANDARDIZED_FORMAT_JTIDS_MIDS_TADIL_J = 100, ///< Link 16 Standardized Format (JTIDS/MIDS/TADIL J)
      LINK_16_ENHANCED_DATA_RATE_EDR_JTIDS_MIDS_TADIL_J = 101, ///< Link 16 Enhanced Data Rate (EDR JTIDS/MIDS/TADIL-J)
      JTIDS_MIDS_NET_DATA_LOAD_TIMS_TOMS = 102, ///< JTIDS/MIDS Net Data Load (TIMS/TOMS)
      LINK_22 = 103, ///< Link 22
      AFIWC_IADS_COMMUNICATIONS_LINKS = 104, ///< AFIWC IADS Communications Links
      F_22_INTRA_FLIGHT_DATA_LINK_IFDL = 105, ///< F-22 Intra-Flight Data Link (IFDL)
      L_BAND_SATCOM = 106, ///< L-Band SATCOM
      TSAF_COMMUNICATIONS_LINK = 107, ///< TSAF Communications Link
      ENHANCED_SINCGARS_7_3 = 108, ///< Enhanced SINCGARS 7.3
      F_35_MULTIFUNCTION_ADVANCED_DATA_LINK_MADL = 109, ///< F-35 Multifunction Advanced Data Link (MADL)
      CURSOR_ON_TARGET = 110, ///< Cursor on Target
      ALL_PURPOSE_STRUCTURED_EUROCONTROL_SURVEILLANCE_INFORMATION_EXCHANGE_ASTERIX = 111, ///< All Purpose Structured Eurocontrol Surveillance Information Exchange (ASTERIX)
      VARIABLE_MESSAGE_FORMAT_VMF_OVER_COMBAT_NET_RADIO_VMF_OVER_CNR = 112, ///< Variable Message Format (VMF) over Combat Net Radio (VMF over CNR)
      LINK_16_SURROGATE_FOR_NON_NATO_TDL = 113, ///< Link 16 Surrogate for Non-NATO TDL
      MQ_1_9_C_BAND_LOS_UPLINK = 114, ///< MQ-1/9 C-Band LOS Uplink
      MQ_1_9_C_BAND_LOS_DOWNLINK = 115, ///< MQ-1/9 C-Band LOS Downlink
      MQ_1_9_KU_BAND_SATCOM_UPLINK = 116, ///< MQ-1/9 Ku-Band SATCOM Uplink
      MQ_1_9_KU_BAND_SATCOM_DOWNLINK = 117, ///< MQ-1/9 Ku-Band SATCOM Downlink
      WEAPONS_DATALINK_SDB_II = 118, ///< Weapons Datalink (SDB II)
      COMMON_INTERACTIVE_BROADCAST_CIB = 120, ///< Common Interactive Broadcast (CIB)
      JOINT_RANGE_EXTENSION_APPLICATION_PROTOCOL_A_JREAP_A = 121, ///< Joint Range Extension Application Protocol A (JREAP A)
      JPALS_DATA_LINK = 125, ///< JPALS Data Link
      ONESAF_IADS_COMMUNICATIONS_LINK = 126, ///< OneSAF IADS Communications Link
      TACTICAL_TARGETING_NETWORK_TECHNOLOGY_TTNT_APPLICATION = 127, ///< Tactical Targeting Network Technology (TTNT) Application
   };

}

void init_entities(DIS::RadarSignalPdu& radar)
{
   /// basic pdu header info
   {
      radar.setProtocolVersion(7);
      radar.setExerciseID(0);
      radar.setPduType(1);
      radar.setProtocolFamily(1);
      radar.setTimestamp(9999);
      radar.setLength(35);
      radar.setPadding(8);
   }

   /// entity id data
   {
      // the radio
      DIS::EntityID radio_ref_id;
      radio_ref_id.setSite(3);
      radio_ref_id.setApplication(15);
      radio_ref_id.setEntityNumber(3000);

      // EntityId has and is a simulation address
      DIS::SimulationAddress radar_sim_addr;
      radar_sim_addr = radio_ref_id.getSimulationAddress();

      radar.setRadioReferenceID( radio_ref_id );
   }

   // signal specific info
   {
      radar.setRadioNumber(20);
      radar.setEncodingScheme(Example::SignalEncodingClass::APPLICATION_SPECIFIC_DATA);
      /// indicates the TDL type of the data field of this PDU.  This value
      /// should be set to siso::SIGNAL_TDL_TYPE_OTHER when the data portion of
      /// this PDU does not represent a TDL message.
      radar.setTdlType(Example::SignalTDLType::OTHER);
      radar.setSampleRate(256);
      // radar.setDataLength(); // automatically set
      std::vector<DIS::OneByteChunk> radar_data;
      DIS::OneByteChunk chunk;
      unsigned int mult = sizeof(int) / sizeof(char);
      std::cout << "chars per int " << mult << std::endl;

      unsigned int temp = 10;
      char bytes[sizeof(temp)];
      std::copy(static_cast<const char*>(static_cast<const void*>(&temp)),
                static_cast<const char*>(static_cast<const void*>(&temp)) + sizeof(temp),
                bytes);
      for (unsigned int i = 0; i < sizeof(temp); ++i)
      {
         std::cout << i << " test " << bytes[i] << std::endl;
         // chunk.setOtherParameters(( char )i);
      }

      // for (unsigned int i = 0; i < 35; ++i)
      // {
      //    char bytes[sizeof i];
      //    std::copy(static_cast<const char*>(static_cast<const void*>(&i)),
      //             static_cast<const char*>(static_cast<const void*>(&i)) + sizeof i,
      //             bytes);
      //    chunk.setOtherParameters(( char )i);
      //    radar_data.push_back( chunk );
      // }
      radar.setData(radar_data);
   }

   // entity type data
   // {
      // // a T-72M
      // DIS::EntityType t72m;
      // t72m.setCategory( 1 );
      // t72m.setCountry( 222 );
      // t72m.setDomain( 1 );
      // t72m.setEntityKind( 1 );
      // t72m.setExtra( 0 );
      // t72m.setSpecific( 2 );
      // t72m.setSubcategory( 2 );

      // enemy.setEntityType( t72m );
   // }

   // dead reckoning
   // {
   //    DIS::DeadReckoningParameters drp;
   //    drp.setDeadReckoningAlgorithm( Example::DRM_FVW );

   //    friendly0.setDeadReckoningParameters( drp );
   //    friendly1.setDeadReckoningParameters( drp );
   //    enemy.setDeadReckoningParameters( drp );
   // }


   //  friendly0.setLength( friendly0.getMarshalledSize());
   // friendly1.setLength( friendly1.getMarshalledSize());
   // enemy.setLength(enemy.getMarshalledSize());
}

int main(int argc, char* argv[])
{
   unsigned int port(62040);
   std::string ip("224.0.0.1");
   if( argc > 2 )
   {
      port = Example::ToType<unsigned int>( argv[1] );
      ip = argv[2];
   }

   /// the basic pieces for sending data
   Example::Connection multicast;
   multicast.Connect( port , ip , false);
   DIS::DataStream buffer( DIS::BIG );

   DIS::RadarSignalPdu radar;

   init_entities( radar );

   // DIS::DetonationPdu tank_round;
   // init_effects( tank_round, friendly[0].getEntityID(), enemy.getEntityID());

   // // -- initialize the flight controllers -- //
   // // the holding location of the friendly aircraft
   // Example::Point3d IP;
   // IP.x = 50.f;
   // IP.y = 50.f; // altitude?
   // IP.z = 50.f;
   // Example::HeloFlightDynamics helo_flight_dynamics_0(Example::DegreesToRadians(20.f),20., IP, 0.);
   // IP.x = 75.f;
   // IP.y = 75.f; // altitude?
   // IP.z = 75.f;
   // Example::HeloFlightDynamics helo_flight_dynamics_1(Example::DegreesToRadians(40.f),40., IP, 0.);

   // Example::TankDynamics tank_dynamics( Example::DegreesToRadians(10.f), Example::DegreesToRadians(20.f) );
   // // Initialize the timer
   // Example::Timer timer;
   // timer.Update();

   // // define the content to be sent of the network
   // double sim_time = 0;
   // double dt = 0;
   // unsigned int frame_stamp=0;

   // Example::TimedAlert isDetonationReady(10.0);   // alert us at 10.0 second intervals
   // Example::TimedAlert isTimeToPrintStatistics(5.0);   // alert us at 10.0 second intervals

   // double last_time = timer.GetSeconds();

   // // the simulation loop
   // ///\todo find an exit condition so we don't need to explicitly kill the app
   // while( true )
   // {
   //    timer.Update();
   //    double current_time = timer.GetSeconds();
   //    dt = current_time - last_time;
   //    sim_time += dt;
   //    last_time = current_time;

   //    // use the dynamics to update the entities' state.
   //    UpdateHelo( friendly[0], helo_flight_dynamics_0, dt, frame_stamp );
   //    UpdateHelo( friendly[1], helo_flight_dynamics_1, dt, frame_stamp );
   //    UpdateTank( enemy, tank_dynamics, dt, frame_stamp );

   //    // serialize for network send
   //    friendly[0].marshal( buffer );
   //    friendly[1].marshal( buffer );
   //    enemy.marshal( buffer );

   //    // Are we ready for le boom boom?
   //    if( isDetonationReady(dt) )
   //    {
   //       tank_round.marshal( buffer );
   //       // some feedback
   //       std::cout << "detonation!" << std::endl;
   //    }

   //    // some feedback
   //    if( isTimeToPrintStatistics(dt) )
   //    {
   //       std::cout << "frame:" << frame_stamp
   //          << "\t dt:" << dt
   //          //<< " | x:" << temp_position.getX()
   //          //<< " | y:" << temp_position.getY()
   //          << std::endl;
   //    }

   //    // send it over the line
   //    multicast.Send( &buffer[0] , buffer.size() );

   //    // clear for next frame
   //    buffer.clear();

   //    // increase for next frame
   //    frame_stamp++;

   //    Example::sleep( 10000 );
   // }

   multicast.Disconnect();
   return 0;
}
