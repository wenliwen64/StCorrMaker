#ifndef STV0CAN_INCLUDED
#define STV0CAN_INCLUDED
#include "TChain.h"
#include "StCorCuts.h"

class StV0Cand:public StParticle{
    public:
       StV0Cand(const TMap& leavesMap, const int& candno);
       inline virtual ~StV0Cand() {}
       virtual bool passCuts(const StV0Cuts& cuts); // apply pre-defined cuts
       inline virtual bool isGood() const{ return m_status; } // check if good candidates
       inline virtual Int_t dau1Id() const{ return m_dau1id; }
       inline virtual Int_t dau2Id() const{ return m_dau2id; }
       //inline virtual Double_t pt() const{ return m_pt; } 
       //inline virtual Double_t px() const{ return m_px; } 
       //inline virtual Double_t py() const{ return m_py; } 
       //inline virtual Double_t pz() const{ return m_pz; } 
       //inline virtual Double_t eta() const{ return m_eta; } 
       //inline virtual Double_t phi() const{ return m_phi; } 
       //inline virtual Double_t dcaGlobal() const{ return m_dcaglobal; } 
       inline virtual Double_t decLen() const{ return m_declen; } 
       inline virtual Double_t dau1Dca() const{ return m_dau1Dca; } 
       inline virtual Double_t dau2Dca() const{ return m_dau2Dca; } 
       inline virtual Double_t dca1to2() const{ return m_dca1to2; } 
       inline virtual Double_t mass() const{ return m_mass; }
       inline virtual Double_t track1_nsigma() const{ return m_track1_nsigma; }
       inline virtual Double_t track2_nsigma() const{ return m_track2_nsigma; }
    private:
       bool m_status; 
       Int_t m_dau1Id;
       Int_t m_dau2Id;
       Double_t m_pt; 
       Double_t m_px; 
       Double_t m_py; 
       Double_t m_pz; 
       Double_t m_eta;
       Double_t m_phi;
       Double_t m_dcaglobal;
       Double_t m_declen;
       Double_t m_dau1dca;
       Double_t m_dau2dca;
       Double_t m_dca1to2; 
       Double_t m_mass;
       Double_t m_track1_nsigma;
       Double_t m_track2_nsigma;
       Double_t m_en;
       Double_t computePhi(Double_t px, Double_t py);
       Double_t computeEnergy(Double_t pt, Double_t eta);
};

#endif
