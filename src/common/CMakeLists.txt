target_sources(common_interface
  INTERFACE
  Endian.h
  IBufferProcessor.h
  IPacketProcessor.h
  Masks.h
  msLibMacro.h
  PacketFactory.h
  PDUType.h
)

target_sources(common_utils
  PRIVATE
  Conversion.cpp
  DataStream.cpp
)
  