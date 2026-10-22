/*
 * mod-azeroth-flying - optional flying mounts in Eastern Kingdoms and Kalimdor.
 * Released under GNU AGPL v3: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "AscensionMountSpeed.h"
#include "AreaDefines.h"
#include "Config.h"
#include "Player.h"
#include "ScriptMgr.h"

class AzerothFlyingPlayerScript : public PlayerScript
{
public:
    AzerothFlyingPlayerScript() : PlayerScript("AzerothFlyingPlayerScript", { PLAYERHOOK_ON_UPDATE_ZONE }) { }

    void OnPlayerUpdateZone(Player* player, uint32 /*newZone*/, uint32 /*newArea*/) override
    {
        if (!player || !player->IsFlying())
            return;

        if (!sConfigMgr->GetOption<bool>("AzerothFlying.Enable", false))
            return;

        uint32 const map = player->GetMapId();
        if (map != MAP_EASTERN_KINGDOMS && map != MAP_KALIMDOR)
            return;

        // Do not let a player stay in the air over a capital or Teldrassil. The core's
        // CanFly check blocks mounting there; this catches a flight that started outside.
        if (AscensionMountSpeed::IsNoFlyArea(player))
            player->Dismount();
    }
};

void AddSC_mod_azeroth_flying()
{
    new AzerothFlyingPlayerScript();
}
