# mod-azeroth-flying

Optional flying mounts in **Eastern Kingdoms** and **Kalimdor** for a CoA/AFK Realm server.

> **Azeroth was not built for flying.** Expect clipping, stuck spots, skipped quest paths,
> unintended shortcuts and PvP advantages. This is a quality-of-life option for testers and
> servers that want it; use it at your own risk. It is not supported on official realms.

## What it does

- Lets mounts that already have a flying effect fly in Eastern Kingdoms and Kalimdor.
- Leaves Outland and Northrend flying exactly as the core has it.
- Keeps the riding-skill requirement and the Northrend Cold Weather Flying requirement.
- Keeps battleground, instance, area-flag and battlefield restrictions.
- Adds a configurable no-fly list for the old-world capitals (Stormwind, Ironforge,
  Darnassus/Teldrassil, the Exodar, Orgrimmar, Undercity, Thunder Bluff and Silvermoon
  by default). Entering one while flying dismounts the player.
- Does not add flying to mounts that have no flying effect.

## Configuration

`conf/mod_azeroth_flying.conf.dist`:

```ini
AzerothFlying.Enable = 0
AzerothFlying.NoFlyAreas = "141,1519,1537,1657,3557,1637,1497,1638,3487"
```

- `AzerothFlying.Enable`: `0` (default) leaves the old world as it is; `1` enables flying
  in Eastern Kingdoms and Kalimdor.
- `AzerothFlying.NoFlyAreas`: comma-separated area or zone ids where flying is not allowed.
  An empty value disables the list; then the capitals can be flown too.

The options appear in AFK Realm's server settings after the module is installed.

## Installation

**With AFK Realm:** install **mod-azeroth-flying** from *Modules by AFK Realm*. AFK Realm
downloads it, applies the core patch at every build and rebuilds the server. Set
`AzerothFlying.Enable = 1` in the server settings afterwards and restart the server.

**By hand:**

1. Put this folder into `modules` next to `mod-playerbots` (or any other module).
2. Apply `patches/core-azeroth-flying.patch` to the core source.
3. Run CMake and build the server.
4. Copy `conf/mod_azeroth_flying.conf.dist` to `configs/modules/mod_azeroth_flying.conf`
   and set `AzerothFlying.Enable = 1`.
5. Restart the server.

The module is server-side only. Players do not need a client patch.

## Compatibility

The module patches `src/server/coa/AscensionMountSpeed.cpp` and keeps the core's
`LearnedMountFlight` and `LearnedMountSpeed` scripts registered. It does not replace them.
If a future CoA core changes that file, the patch may need an update.
