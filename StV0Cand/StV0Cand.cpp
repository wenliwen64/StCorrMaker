#include "TLeaf.h"
#include "TMap.h"
#include "TVector2.h"
#include "utilities.h" // include constants
StV0Cand::StV0Cand(const TMap& leavesMap, const int& candno, const StV0Cuts& cuts){
    m_dau1Id = m_leavesMap.FindObject("dau1Id")->GetValue(m_candno);
    m_dau2Id = m_leavesMap.FindObject("dau2Id")->GetValue(m_candno);
    m_pt = m_leavesMap.FindObject("pt")->GetValue(m_candno);
    m_px = m_leavesMap.FindObject("pt")->GetValue(m_candno);
    m_py = m_leavesMap.FindObject("pt")->GetValue(m_candno);
    m_eta = m_leavesMap.FindObject("eta")->GetValue(m_candno);
    m_phi = computePhi(m_px, mpy); 
    m_dcaglobal = m_leavesMap.FindObject("dcaglobal")->GetValue(m_candno);
    m_declen = m_leavesMap.FindObject("declen")->GetValue(m_candno);
    m_dau1dca = m_leavesMap.FindObject("dau1Dca")->GetValue(m_candno);
    m_dau2dca = m_leavesMap.FindObject("dau2Dca")->GetValue(m_candno);
    m_dca1to2 = m_leavesMap.FindObject("dca1to2")->GetValue(m_candno);
    m_mass = m_leavesMap.FindObject("mass")->GetValue(m_candno);
    m_track1_nsigma = m_leavesMap.FindObjet("track1nsigma")->GetValue(m_candno);
    m_track2_nsigma = m_leavesMap.FindObjet("track2nsigma")->GetValue(m_candno);
    m_en = computeEnergy(m_pt, m_eta);

    m_status = passCuts(cuts)? true:false;
}

bool StV0Cand::passCuts(const StV0Cuts& cuts){
    return (dau1Id() != dau2Id() && cuts.mass(mass())
                            && cuts.dcaGlobal(dcaGlobal()) 
			    && cuts.pt(pt())
			    && cuts.eta(eta())
			    && cuts.track1_nsigma(track1_nsigma())
			    && cuts.track2_nsigma(track2_nsigma())
			    && cuts.decLen(decLen())
			    && cuts.dau1Dca(dau1Dca())
			    && cuts.dau2Dca(dau2Dca())
			    && cuts.dca1to2(dca1to2())
			    && cuts.lowPtDca(dau1Dca(), dau2Dca()))? true:false;
}
//======Private=====
Double_t StV0Cand::computePhi(Double_t px, Double_t py){
    TVector2 v0Phi(px, py); 
    Double_t phi = v0Phi.Phi();
    if(phi > PI) phi -= 2 * PI;//TODO
    else if(phi < - PI) phi += 2 * PI;

    return phi;
}

Double_t StV0Cand::computeEnergy(Double_t pt, Double_t eta){
    return sqrt(PDGV0MASS * PDGMASS + pow(pt * cosh(eta), 2));//TODO
}
