target_sources(test_Sender
  PRIVATE
  "RadarSignalPdu.cpp"
  "Utils.cpp"
  "main.cpp"
)

target_sources(test_Receiver
  PRIVATE
  "main_receive.cpp"
  "Utils.cpp"
  "RadarSignalPduProcessor.cpp"
)
