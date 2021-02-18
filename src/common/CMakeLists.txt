# this only works with INTERFACE set, but the gives a 
# warning about using an absolute path
# target_sources(common_interface
#  PUBLIC
#   Endian.h
#   IBufferProcessor.h
#   IPacketProcessor.h
#   Masks.h
#   msLibMacro.h
#   PDUType.h
# )

target_sources(common_utils
  PRIVATE
  Conversion.cpp
  DataStream.cpp
)
  
