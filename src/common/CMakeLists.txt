target_sources(common_interface
  PRIVATE
  msLibMacro.h
  Endian.h
  Masks.h
  IPacketProcessor.h
  PDUType.h
  IBufferProcessor.h
)

target_sources(common_utils
  PRIVATE
  Conversion.cpp
  DataStream.cpp
)
  
