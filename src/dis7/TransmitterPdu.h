#ifndef TRANSMITTERPDU_H
#define TRANSMITTERPDU_H

#include <dis7/EntityID.h>
#include <dis7/EntityType.h>
#include <dis7/Vector3Double.h>
#include <dis7/Vector3Float.h>
#include <dis7/ModulationType.h>
#include <dis7/Vector3Float.h>
#include <dis7/Vector3Float.h>
#include <vector>
#include <dis7/RadioCommunicationsFamilyPdu.h>
#include <common/DataStream.h>
#include <common/msLibMacro.h>


namespace DIS
{
// Detailed information about a radio transmitter. This PDU requires manually written code to complete, since the modulation parameters are of variable length. Section 7.7.2 UNFINISHED

// Copyright (c) 2007-2012, MOVES Institute, Naval Postgraduate School. All rights reserved. 
// Licensed under the BSD open source license. See http://www.movesinstitute.org/licenses/bsd.html
//
// @author DMcG, jkg

class EXPORT_MACRO TransmitterPdu : public RadioCommunicationsFamilyPdu
{
protected:
  /** Type of radio */
  EntityType _radioType;

  /** transmit state */
  unsigned char _transmitState;

  /** input source */
  unsigned char _inputSource;

  /** Location of antenna */
  Vector3Double _antennaLocation;

  /** relative location of antenna */
  Vector3Float _relativeAntennaLocation;

  /** antenna pattern type */
  unsigned short _antennaPatternType;

  /** antenna pattern length */
  unsigned short _antennaPatternLength;

  /** Center frequency being used in hertz */
  unsigned long _frequency;

  /** transmit frequency Bandwidth in hertz */
  float _transmitFrequencyBandwidth;

  /** transmission power in decibel-milliwatts */
  float _power;

  /** modulation */
  ModulationType _modulationType;

  /** crypto system enumeration */
  unsigned short _cryptoSystem;

  /** crypto system key identifer */
  unsigned short _cryptoKeyId;

  /** how many modulation parameters we have */
  unsigned char _modulationParameterLength;

  /** padding1 */
  unsigned char _padding1;

  /** padding2 */
  unsigned short _padding2;

  /** variable length list of modulation parameters */
  std::vector<Vector3Float> _modulationParametersList;

  /** variable length list of antenna pattern records */
  std::vector<Vector3Float> _antennaPatternList;


 public:
    TransmitterPdu();
    virtual ~TransmitterPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    EntityType& getRadioType();
    const EntityType&  getRadioType() const;
    void setRadioType(const EntityType    &pX);

    unsigned char getTransmitState() const; 
    void setTransmitState(unsigned char pX); 

    unsigned char getInputSource() const; 
    void setInputSource(unsigned char pX); 

    Vector3Double& getAntennaLocation();
    const Vector3Double&  getAntennaLocation() const;
    void setAntennaLocation(const Vector3Double    &pX);

    Vector3Float& getRelativeAntennaLocation();
    const Vector3Float&  getRelativeAntennaLocation() const;
    void setRelativeAntennaLocation(const Vector3Float    &pX);

    unsigned short getAntennaPatternType() const; 
    void setAntennaPatternType(unsigned short pX); 

    unsigned short getAntennaPatternLength() const; 
    void setAntennaPatternLength(unsigned short pX); 

    unsigned long long getFrequency() const;
    void setFrequency(unsigned long long pX);

    float getTransmitFrequencyBandwidth() const; 
    void setTransmitFrequencyBandwidth(float pX); 

    float getPower() const; 
    void setPower(float pX); 

    ModulationType& getModulationType();
    const ModulationType&  getModulationType() const;
    void setModulationType(const ModulationType    &pX);

    unsigned short getCryptoSystem() const; 
    void setCryptoSystem(unsigned short pX); 

    unsigned short getCryptoKeyId() const; 
    void setCryptoKeyId(unsigned short pX); 

    unsigned char getModulationParameterLength() const;
    void setModulationParameterLength(unsigned char pX);

    unsigned char getPadding1() const;
    void setPadding1(unsigned char pX); 

    unsigned short getPadding2() const; 
    void setPadding2(unsigned short pX); 


    std::vector<Vector3Float>& getModulationParametersList(); 
    const std::vector<Vector3Float>& getModulationParametersList() const; 
    void setModulationParametersList(const std::vector<Vector3Float>&    pX);

    std::vector<Vector3Float>& getAntennaPatternList(); 
    const std::vector<Vector3Float>& getAntennaPatternList() const; 
    void setAntennaPatternList(const std::vector<Vector3Float>&    pX);


     virtual int getMarshalledSize() const;

     bool operator ==(const TransmitterPdu& rhs) const;
};
}

#endif
// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
