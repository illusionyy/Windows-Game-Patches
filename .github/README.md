# Windows-Game-Patches

[![MSBuild](https://github.com/illusion0001/Windows-Game-Patches/actions/workflows/msbuild.yml/badge.svg)](https://github.com/illusion0001/Windows-Game-Patches/actions/workflows/msbuild.yml)

[Latest Release](https://github.com/illusion0001/Windows-Game-Patches/releases/latest)

# Patches

<details><summary>
 
  ### 007: First Light
</summary>
  
  - Disable TAA

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the Retail folder.
  - Copy `dinput8.dll` from folder `!ASI_Loader_x64` to game folder.
  - `007FirstLight.NoTAA.asi`

#### Notes

- Keep Global Illumination setting at Medium level or below to avoid lighting or shadow glitches. 

#### Last tested game version: 1.3.2 (29 October 2026)
</details>
<details><summary>

  ### Assassin's Creed Mirage
</summary>
  
  - Disable TAA
  - Disable CA

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the Win64 folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `ACMirage.NoTAA.asi`
</details>
<details><summary>
  
  ### Battlefield V
</summary>

  - Disable TAA
  - Custom Internal AA Options.
    - PostProcessAAMode_None: `0`
    - PostProcessAAMode_FxaaLow: `1`
    - PostProcessAAMode_FxaaMedium: `2`
    - PostProcessAAMode_FxaaHigh: `3`
    - PostProcessAAMode_FxaaCompute: `4`
    - PostProcessAAMode_FxaaComputeExtreme: `5`
    - PostProcessAAMode_Smaa1x: `6`
    - PostProcessAAMode_SmaaT2x: `7`
    - PostProcessAAMode_TemporalAA: `8`

#### Installation
- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
- ***This has not been tested online, use at your own risk!***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `BFV.NoTAA.asi`
</details>
<details><summary>
  
  ### Bright Memory: Infinite
</summary>

  - Disable TAA
  - Disable Forced Sharpening

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the Win64 folder. (`BrightMemoryInfinite\Binaries\Win64\`).
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `BrightMemoryInfinite.NoTAA.asi`
</details>

<details><summary>

### Control
</summary>

  - Skip Startup Logos
  - Dev Menu Restore (HDR Version 1.30 is supported) <!-- ~~its a new compile version as a mod, are they allowed to do that?~~ -->
  - Debug Camera (Press L3 and Triangle when `bEnableDevMenu` is enabled)

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - **Only tested with Steam version**
- Extract the following contents of the release zip into the root game folder.
  - Rename original `bink2w64.dll` to `bink2w64Hooked.dll` for ASI Loader.
  - Extract `dinput8.dll` from zip `!ASI_Loader_x64` and rename to `bink2w64.dll` and copy to game folder.
  - Extract `Control.Patches.asi` to game folder.
  - Run game once to generate ini and close it.
  - Enable config for desried patches.

#### Special Thanks
- Original [Control Dev Menu](https://www.nexusmods.com/control/mods/28) mod for references in Debug Panel.

</details>

<details><summary>

### Crysis Warhead
</summary>

  - Restore Chicken Bullets

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - *This patch has no ini file!*
- Extract the following contents of the release zip into the root game folder.
  - Extract `dinput8.dll` from zip `!ASI_Loader_x64` and rename to `version.dll` and copy to game `Bin64` folder.
  - Extract `CrysisWarhead.Patches.asi` to game `Bin64` folder.
- Once in game, open console and type `chickens` to enable.

#### Installation

- Only 64 bit version of game is supported.
  - Tested version is Steam 1.1.711
- OS:
  - Windows 7 x64 and newer:
    - ASI Loader only supports Windows 7 due to missing `AcquireSRWlockExclusive` and few others in XP x64 kernel32.

</details>
<details><summary>

### Dead Space (2023)
</summary>

  - Disable Forced TAA

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - *This patch has no ini file! meaning TAA will be disabled without any config adjustments.*
- Extract the following contents of the release zip into the root game folder.
  - Extract `dinput8.dll` from zip `!ASI_Loader_x64` and rename to `winmm.dll` and copy to game folder.
  - Extract `DeadSpace.NoTAA.asi` to game folder.
  - Create `winmm.ini` and add the following to the new created file: (See [#36](https://github.com/illusion0001/Windows-Game-Patches/issues/36#issuecomment-2525569596))
    ```ini
    [GlobalSets]
    DontLoadFromDllMain=0
    ```

</details>
<details><summary>


### Dragon's Dogma 2
</summary>

  - Disable Forced Sharpening

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Download [REFramework](https://github.com/praydog/REFramework) and extract `dinput8.dll` into the game root folder.
  - Extract `DD2.Sharpness.dll` from the release zip in the folder `Dragons Dogma 2\reframework\plugins`.

</details>
<details><summary>

### Death Stranding (original and Director's Cut)
</summary>

  - Force AA mode (None, FXAA or TAA)
  - Skip savegame checks (for savegame transfer between different versions/profiles)

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `version.dll` and copy to game folder.
  - `version.ini`
  - `DeathStranding.Fix.asi`
</details>
<details><summary>
  
### Elden Ring
</summary>

  - Force TAA off
  - Disable Chromatic Aberration (thanks to [techiew](https://github.com/techiew/EldenRingMods) for the original fix)

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game folder. (`ELDEN RING\Game\`).
  - Copy `dinput8.dll` from folder `!ASI_Loader_x64` to game folder.
  - `EldenRing.NoTAA.asi`
</details>
<details><summary>
  
### Grand Theft Auto V Enhanced
</summary>

  - Skip start-up movies and legal text (always enabled)
  - Unlock FPS (max. 300 FPS)
    - Uses work by [NTA](https://github.com/citizenfx/fivem/blob/4e9aa42c700f88735a2b9c2f51738568daf597e4/code/components/gta-core-five/src/GameAudioState.cpp#L434) and [Gogsi/GTAV.AudioFixes](https://github.com/Gogsi/GTAV.AudioFixes/blob/e0588ec4667898ceec5a5bbcf628fcb8c46ba09d/script.cpp#L42)
    - Please see the explanation in the settings file for more information

#### Installation

- **Note:** ***Please make sure any executable HEX edits are removed/reverted first***.
  - Turn off BattleEye anti-cheat in Rockstar Launcher settings (alternatively, use the `-nobattleye` launch option if, for example, playing via Steam)
    - ![](https://github.com/user-attachments/assets/4c11df02-6f55-45bd-92ed-4269a7ce966d)
  - Extract the following contents of the release zip into the game folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `dsound.dll` and copy to game folder.
  - Copy  `GTA5_Enhanced.Patches.asi` to game folder.

**For Linux users:** use the followng launch options (tested on Steam).
```
WINEDLLOVERRIDES="dsound=n,b" %command% -nobattleye
```

### Credits
- Uses work by [NTA](https://github.com/citizenfx/fivem/blob/4e9aa42c700f88735a2b9c2f51738568daf597e4/code/components/gta-core-five/src/GameAudioState.cpp#L434) and [Gogsi/GTAV.AudioFixes](https://github.com/Gogsi/GTAV.AudioFixes/blob/e0588ec4667898ceec5a5bbcf628fcb8c46ba09d/script.cpp#L42)
- Please see notice in settings file for more information

</details>
<details><summary>

### God of War
</summary>

  - Disable TAA
  - Disable Forced Sharpening
  - Disable Static Vignette
  - Disable Depth of Field

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `GoW.NoTAA.asi`
</details>
<details><summary>

### God of War: Ragnarök
</summary>

  - Disable TAA
  - Disable Static Vignette
  - Disable Depth of Field

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `GoWR.NoTAA.asi`
</details>
<details><summary>

### HITMAN 3
</summary>

  - Disable TAA
  - Disable Forced Sharpening

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game folder. (`HITMAN3\Retail\`).
  - Copy `dinput8.dll` from folder `!ASI_Loader_x64` to game folder.
  - `Hitman3.NoTAA.asi`
</details>
<details><summary>

### Indiana Jones and the Great Circle
</summary>

  - Disable TAA

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game folder. (`The Great Circle\`).
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `TheGreatCircle.NoTAA.asi`
</details>
<details><summary>

### Lies of P
</summary>

  - Disable TAA
  - Disable Forced Sharpening
  - Disable Depth of Field

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the Win64 folder. (`Lies of P Demo\LiesofP\Binaries\Win64\`).
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `LiesOfP.NoTAA.asi`

#### Last tested game version: 1.14.0.0 (1 October 2026)
</details>
<details><summary>

### LEGO Horizon Adventures
</summary>

  - Disable TAA
  - Disable Depth of Field

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the Win64 folder. (`LEGO Horizon Adventures\Glow\Binaries\Win64\`).
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `LegoHorizonAdventures.NoTAA.asi`
</details>
<details><summary>
 
### Marvel's Guardians of the Galaxy
</summary>

  - Disable TAA

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game folder. (`Marvel's Guardians of the Galaxy\bin`).
  - Copy `dinput8.dll` from folder `!ASI_Loader_x64` to game folder.
  - `GotG.NoTAA.asi`
</details>

<details><summary>

### NieR Automata
</summary>

  - Flag Menu (Press Home on keyboard or R3 + L1 on controller)
    - Backspace or Circle to back out of a menu

#### Installation
- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `NierAutomata.DebugFeatures.asi`

#### Speical Thanks
  - Emoose [LodMod](https://github.com/emoose/NieRAutomata-LodMod) for debug flag enums!

</details>

<details><summary>

### NieR Replicant ver.1.22474487139
</summary>

  - Remove FPS Limit
#### Installation
- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `NierReplicant.Fix.asi`
</details>
<details><summary>
  
### Planet of Lana
</summary>

  - Disable TAA

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `d3d11.dll` and copy to game folder.
  - `PlanetOfLana.NoTAA.asi`
  - `d3d11.ini`
</details>

<details><summary>

### Quantum Break
</summary>

  - Skip Startup Logos
  - Dev Menu Restore

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - **Only tested with Steam version**
- Rename original `bink2w64.dll` in game `dx11` folder to `bink2w64Hooked.dll` for ASI Loader.
- Extract `dinput8.dll` from zip `!ASI_Loader_x64` and rename to `bink2w64.dll` and copy to game `dx11` folder.
- Extract `QuantumBreak.Patches.asi` to game `dx11` folder.
- Run game once to generate ini and close it.
- Enable config for desried patches.

#### Special Thanks
- Original [Control Dev Menu](https://www.nexusmods.com/control/mods/28) mod for references in Debug Panel.

</details>

<details><summary>

### Red Dead Redemption 2
</summary>

#### Notes

  - Please use version [1.0.136-321f7350](https://github.com/illusion0001/Windows-Game-Patches/releases/tag/1.0.136-321f7350) in the meantime while cmake transitioning is in progress.

#### Patches
  - Skip Legal and Logo videos
  - Load directly into benchmark mode (5th index, Saint Denis benchmark)

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder. (next to where `RDR2.exe` is located).
  - Copy `dinput8.dll` from folder `!ASI_Loader_x64` to game folder.
  - `RDR3.Patches.asi`
  - `ScriptHookRDR2.dll`

#### Credits

This patch uses following work:
- [ScriptHook SDK for RDR2](http://www.dev-c.com/rdr2/scripthookrdr2/)
- [Main and Legal Menu Skip Mod](https://www.rdr2mods.com/downloads/rdr2/other/304-main-and-legal-menu-skip/)

</details>
<details><summary>

### Remnant II
</summary>

  - Disable TAA
  - Disable Forced Sharpening

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the Win64 folder. (`Remnant 2\Remnant2\Binaries\Win64\`).
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `Remnant2.NoTAA.asi`
</details>
<details><summary>
  
### Resident Evil 4 Remake
</summary>

  - Disable Forced Sharpening

#### Installation
- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Download [REFramework](https://github.com/praydog/REFramework) and extract `dinput8.dll` into the game root folder.
  - Extract `RE4.Sharpness.asi` from the release zip in the folder `RESIDENT EVIL 4  BIOHAZARD RE4\reframework\plugins` and rename it into `RE4.Sharpness.dll`.
</details>
<details><summary>

### Resident Evil Village
</summary>

  - Disable TAA and Forced Sharpening
  - Disable Forced Sharpening only

#### Installation
- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Download [REFramework](https://github.com/praydog/REFramework) and extract `dinput8.dll` into the game root folder.
  - Extract `RE8.NoTAA.asi` from the release zip in the folder `Resident Evil Village BIOHAZARD VILLAGE\reframework\plugins` and rename it into `RE8.NoTAA.dll`.
</details>
<details><summary>
  
### Uncharted 4 + The Lost Legacy
</summary>

  - Debug Menu (by SunBeam)
    - Controls:
      - Joypad:
        - `L3 + X`: Open Quick Menu
        - `L3 + Circle`: Open Dev Menu
        - `L3 + Square`: Debug Pause
        - `Circle`: Back submenu
        - `X`: Enter\Select Dev Menu Entry
      - Keyboard:
        - `Alt + Tilde`: Open Dev Menu
        - `Tilde + 1`: Open Quick Menu
        - `Tilde`: Back submenu
        - `Enter`: Enter\Select Dev Menu Entry
  - Skip Intro Logo Videos
  - Disable TAA
  - Disable Forced Sharpening
  - Disable Barrel Distortion
  - Disable Screen Zoom
  - Disable Chromatic Aberration
  - Disable Depth of Field
  - Disable Vignette

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `Uncharted4TLL.NoTAA.asi`
</details>
<details><summary>
  
### The Last of Us: Part 1
</summary>

  - Debug Menu
  - Custom Debug Menu (Work in Progress)
  - Restored Active Task Display
  - Extended Debug Menu by [infogram](https://web.archive.org/web/20230413143249/https://cs.rin.ru/forum/viewtopic.php?p=2806625)
    - `1.0.85-44a951ca` now supports game version `1.0.5.0` and newer.

#### Installation

- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `T1X.DebugFeatures.asi`
</details>
<details><summary>
  
### Wo Long: Fallen Dynasty
</summary>

  - Remove 30FPS Limit for Cutscenes (Experimental)
#### Installation
- **Note:** ***Please make sure any executable hex edits are removed/reverted first***.
  - Extract the following contents of the release zip into the game root folder.
  - Rename `dinput8.dll` from folder `!ASI_Loader_x64` to `winmm.dll` and copy to game folder.
  - `WoLong.Fix.asi`
</details>
  
# Credits
- [Lyall](https://github.com/Lyall) for Project Template.
- [Ultimate ASI Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader) for ASI loading.
- [inipp](https://github.com/mcmtroffaes/inipp) for ini reading.
- [length-disassembler](https://github.com/Nomade040/length-disassembler) for length disassembly.
- [tl431](https://github.com/TL431/) for additional game fixes.
