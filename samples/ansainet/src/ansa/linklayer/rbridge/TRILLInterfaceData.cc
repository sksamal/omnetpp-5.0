// Copyright (C) 2013 Brno University of Technology (http://nes.fit.vutbr.cz/ansa)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

/**
 * @file TRILLInterfaceData.cc
 * @author Marcel Marek (mailto:xscrew02@gmail.com), Vladimir Vesely (mailto:ivesely@fit.vutbr.cz)
 * @date 24.3.2013
 * @brief Represents TRILL related data on interface.
 * @detail Represents TRILL related data on interface.
 * @todo Z9
 */

#include "TRILLInterfaceData.h"

namespace inet {

TRILLInterfaceData::TRILLInterfaceData()
{



    // TODO Auto-generated constructor stub

}

TRILLInterfaceData::~TRILLInterfaceData()
{
    // TODO Auto-generated destructor stub
}

void TRILLInterfaceData::setDefaults(void){

    this->disabled = false;

    this->trunk = false;

    this->access = false;

    this->p2p = false;

    this->announcingSet.push_back(1); //TODO A2 FIX change to some configurable default VLAN

    this->enabledgSet.push_back(1);

    this->nonAdj = false;

    this->inhibitionInterval = 30;

    this->disLearning = false;

    this->vlanId = 1;

    this->inhibited = false;

    this->desigVLAN = 1;

    this->vlanMapping = false;
}

int TRILLInterfaceData::getVlanId() const
{
    return vlanId;
}

bool TRILLInterfaceData::isAccess() const
{
    return access;
}

bool TRILLInterfaceData::isDisLearning() const
{
    return disLearning;
}

bool TRILLInterfaceData::isDisabled() const
{
    return disabled;
}

bool TRILLInterfaceData::isP2p() const
{
    return p2p;
}

bool TRILLInterfaceData::isTrunk() const
{
    return trunk;
}

void TRILLInterfaceData::setAccess(bool access)
{
    this->access = access;
}

void TRILLInterfaceData::setDisLearning(bool disLearning)
{
    this->disLearning = disLearning;
}

void TRILLInterfaceData::setDisabled(bool disabled)
{
    this->disabled = disabled;
}

void TRILLInterfaceData::setP2p(bool p2p)
{
    this->p2p = p2p;
}

void TRILLInterfaceData::setTrunk(bool trunk)
{
    this->trunk = trunk;
}

void TRILLInterfaceData::setVlanId(int vlanId)
{
    this->vlanId = vlanId;
}


bool TRILLInterfaceData::isInhibited() const
{
    return inhibited;
}

bool TRILLInterfaceData::isEnabled(int vlanId)
{
    for(VLANVector::iterator it = this->enabledgSet.begin(); it != this->enabledgSet.end(); ++it){
        if((*it) == vlanId){
            return true;
        }
    }
    return false;
}

int TRILLInterfaceData::getDesigVlan() const
{
    return desigVLAN;
}

bool TRILLInterfaceData::isVlanMapping() const
{
    return vlanMapping;
}

int TRILLInterfaceData::getDesiredDesigVlan() const
{
    return desiredDesigVLAN;
}

void TRILLInterfaceData::setDesiredDesigVlan(int desiredDesigVlan)
{
    desiredDesigVLAN = desiredDesigVlan;
}

void TRILLInterfaceData::setVlanMapping(bool vlanMapping)
{
    this->vlanMapping = vlanMapping;
}

void TRILLInterfaceData::setDesigVlan(int desigVlan)
{
    desigVLAN = desigVlan;
}

void TRILLInterfaceData::setInhibited(bool inhibited)
{
    this->inhibited = inhibited;
}

bool TRILLInterfaceData::isAppointedForwarder(int vlanId, TRILLNickname nickname){

    //TODO A2
//    if(nickname == 0){
//        nickname = getNicknameOfThisRBridge();
//    }
    std::map<int, TRILLNickname>::iterator it = this->appointedForwarder.find(vlanId);
    if(it != this->appointedForwarder.end()){
        if((*it).second == nickname){
            return true;
        }
    }else{
        return false;
    }
//    for(VLANVector::iterator iter = appointedForwarder.begin(); iter != appointedForwarder.end(); ++iter){
//        if(vlanId == (*iter)){
//            return true;
//        }
//    }

    return false;
}

void TRILLInterfaceData::setAppointedForwarder(int vlanId, TRILLNickname nickname)
{
    this->appointedForwarder.clear();
    this->appointedForwarder.insert(std::make_pair(vlanId, nickname));
}

void TRILLInterfaceData::addAppointedForwarder(int vlanId, TRILLNickname nickname)
{
    this->appointedForwarder.insert(std::make_pair(vlanId, nickname));
}

void TRILLInterfaceData::clearAppointedForwarder(){
    this->appointedForwarder.clear();
}

/*
 * TODO B2 To be determined if nickname has to match too.
 */
void TRILLInterfaceData::removeAppointedFowrwarder(int vlanId, TRILLNickname nickname)
{
    std::map<int, TRILLNickname>::iterator it = this->appointedForwarder.find(vlanId);
    if(it != this->appointedForwarder.end()){

        this->appointedForwarder.erase(it);
    }else{
//        return false;
    }
}

}
