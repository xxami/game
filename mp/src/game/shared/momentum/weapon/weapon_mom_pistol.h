#pragma once

#include "cbase.h"
#include "weapon/weapon_csbasegun.h"


#ifdef CLIENT_DLL
#define CMomentumPistol C_MomentumPistol
#endif


class CMomentumPistol : public CWeaponCSBaseGun
{
public:
    DECLARE_CLASS(CMomentumPistol, CWeaponCSBaseGun);
    DECLARE_NETWORKCLASS();
    DECLARE_PREDICTABLE();

    CMomentumPistol();

    void Spawn() OVERRIDE;
    void Precache() OVERRIDE;

    void PrimaryAttack() OVERRIDE;
    void SecondaryAttack() OVERRIDE;
    bool Deploy() OVERRIDE;

    void ItemPostFrame() OVERRIDE;

    void PistolFire();
    void FireRemaining(int &shotsFired, float &shootTime) const;
#ifdef WEAPONS_USE_AMMO
    bool Reload() OVERRIDE;
#endif
    void WeaponIdle() OVERRIDE;

    CSWeaponID GetWeaponID(void) const OVERRIDE { return WEAPON_PISTOL; }

private:

    CMomentumPistol(const CMomentumPistol &);

    CNetworkVar(bool, m_bBurstMode);

    int		m_iPistolShotsFired;	// used to keep track of the shots fired during the burst fire mode.
    float	m_flPistolShoot;		// time to shoot the remaining bullets of the burst fire
    float	m_flLastFire;

};