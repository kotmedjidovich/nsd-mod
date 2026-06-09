
#define COLOR_GRAY					0xAEAEAEFF
#define COLOR_WHITE                 0xFFFFFFAA

#define C_WHITE    					"{FFFFFF}"
#define C_GRAY						"{AEAEAE}"

#define SCM                         SendClientMessage

new const g_aPreloadLibs[][] =
{
    "AIRPORT",      "ATTRACTORS",   "BAR",          "BASEBALL",     "BD_FIRE",
    "BEACH",        "BENCHPRESS",   "BF_INJECTION", "BIKE_DBZ",     "BIKED",
    "BIKEH",        "BIKELEAP",     "BIKES",        "BIKEV",        "BLOWJOBZ",
    "BMX",          "BOMBER",       "BOX",          "BSKTBALL",     "BUDDY",
    "BUS",          "CAMERA",       "CAR",          "CAR_CHAT",     "CARRY",
    "CASINO",       "CHAINSAW",     "CHOPPA",       "CLOTHES",      "COACH",
    "COLT45",       "COP_AMBIENT",  "COP_DVBYZ",    "CRACK",        "CRIB",
    "DAM_JUMP",     "DANCING",      "DEALER",       "DILDO",        "DODGE",
    "DOZER",        "DRIVEBYS",     "FAT",          "FIGHT_B",      "FIGHT_C",
    "FIGHT_D",      "FIGHT_E",      "FINALE",       "FINALE2",      "FLAME",
    "FLOWERS",      "FOOD",         "FREEWEIGHTS",  "GANGS",        "GFUNK",
    "GHANDS",       "GHETTO_DB",    "GOGGLES",      "GRAFFITI",     "GRAVEYARD",
    "GRENADE",      "GYMNASIUM",    "HAIRCUTS",     "HEIST9",       "INT_HOUSE",
    "INT_OFFICE",   "INT_SHOP",     "JST_BUISNESS", "KART",         "KISSING",
    "KNIFE",        "LAPDAN1",      "LAPDAN2",      "LAPDAN3",      "LOWRIDER",
    "MD_CHASE",     "MD_END",       "MEDIC",        "MISC",         "MTB",
    "MUSCULAR",     "NEVADA",       "ON_LOOKERS",   "OTB",          "PARACHUTE",
    "PARK",         "PAULNMAC",     "PED",          "PLAYER_DVBYS", "PLAYIDLES",
    "POLICE",       "POOL",         "POOR",         "PYTHON",       "QUAD",
    "QUAD_DBZ",     "RAPPING",      "RIFLE",        "RIOT",         "ROB_BANK",
    "ROCKET",       "RUNNINGMAN",   "RUSTLER",      "RYDER",        "SCRATCHING",
    "SEX",          "SHAMAL",       "SHOP",         "SHOTGUN",      "SILENCED",
    "SKATE",        "SMOKING",      "SNIPER",       "SNM",          "SPRAYCAN",
    "STRIP",        "SUNBATHE",     "SWAT",         "SWEET",        "SWIM",
    "SWORD",        "TANK",         "TATTOOS",      "TEC",          "TRAIN",
    "TRUCK",        "UZI",          "VAN",          "VENDING",      "VORTEX",
    "WAYFARER",     "WEAPONS",      "WOP",          "WUZI"
};  

PreloadAnimations(playerid)
{
    for (new i = 0; i < sizeof(g_aPreloadLibs); i ++) {
        ApplyAnimation(playerid, g_aPreloadLibs[i], "null", 4.0, 0, 0, 0, 0, 0, 1);
    }
    return 1;
}  

UseAnim(playerid, animlib[], animname[], Float:Speed, looping, lockx, locky, lockz, lp, time = 0)
{
	if( GetPVarInt( playerid, "death" ) != 0 ) return 1;
	if( GetPVarInt( playerid, "anim" ) != 0 ) return SCM(playerid,-1,"" #C_GRAY "Нажмите клавишу {ffffff}\"ПРОБЕЛ\" " #C_GRAY "или введите команду {ffffff}/sa " #C_GRAY "чтобы остановить анимацию");
    
    ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp, time);
    ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp, time);
    ApplyAnimation(playerid, animlib, animname, Speed, looping, lockx, locky, lockz, lp, time);
    
    if( GetPVarInt( playerid, "animmessage" ) == 0 ) SCM(playerid,-1,"" #C_GRAY "Нажмите клавишу {ffffff}\"ПРОБЕЛ\" " #C_GRAY "или введите команду {ffffff}/sa " #C_GRAY "чтобы остановить анимацию");
	return SetPVarInt(playerid,"anim",1), SetPVarInt(playerid,"animmessage",1);
}

StopUsingAnim(playerid) 
{
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
    ApplyAnimation(playerid, "CARRY", "crry_prtial", 4.0, 0, 0, 0, 0, 0);
	
	return DeletePVar(playerid, "anim");
}

CMD:sa(playerid) 
{
	if( GetPVarInt( playerid, "anim" ) != 0 ) StopUsingAnim(playerid);
	else return SCM( playerid, -1, "Вы не используете никакую анимацию в данный момент!");
	return true;
}

CMD:handsup(playerid, params[]) {
	UseAnim(playerid, "ROB_BANK","SHP_HandsUp_Scr", 4.0, 0, 1, 1, 1, 0);
	return true;
} 

CMD:aim(playerid, params[]) {
	UseAnim(playerid,"PED","gang_gunstand",3.0,0,1,1,1,0);
	return true;
}

CMD:cellin(playerid, params[]) {
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
	return true;
}

CMD:cellout(playerid, params[]) {
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
	return true;
}


CMD:drunk(playerid, params[]) {
	UseAnim(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
	return true;
}

CMD:kicking(playerid, params[]) {
	UseAnim(playerid,"GANGS","shake_carK",4.0,0,0,0,0,0);
	return true;
}

CMD:bomb(playerid, params[]) {
	UseAnim(playerid, "BOMBER","BOM_Plant",4.0,0,0,0,0,0);
	return true;
}

CMD:bar(playerid, params[]) {
	UseAnim(playerid,"BAR","Barserve_bottle",4.0,0,0,0,0,0);
	return true;
}

CMD:stoptaxi(playerid, params[]) {
	UseAnim(playerid,"PED","IDLE_taxi",4.0,0,0,0,0,0);
	return true;
}

CMD:getarrested(playerid, params[]) {
	UseAnim(playerid,"ped", "ARRESTgun", 4.0, 0, 1, 1, 1, -1);
	return true;
}

CMD:laugh(playerid, params[]) {
	UseAnim(playerid, "RAPPING", "Laugh_01", 4.0, 0, 0, 0, 0, 0);
	return true;
}

CMD:lookout(playerid, params[]) {
	UseAnim(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
	return true;
}

CMD:crossarms(playerid, params[]) {
	UseAnim(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
	return true;
}

CMD:hide(playerid, params[]) {
	UseAnim(playerid, "ped", "cower", 3.0, 1, 0, 0, 0, 0);
	return true;
}

CMD:vomit(playerid, params[]) {
	UseAnim(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
	return true;
}

CMD:eat(playerid, params[]) {
	UseAnim(playerid, "FOOD", "EAT_Burger", 4.1,1,1,1,1,1);
	return true;
}

CMD:sipdrink(playerid, params[]) {
	UseAnim(playerid, "GANGS", "drnkbr_prtl", 4.1,1,1,1,1,1);
	return true;
}

CMD:slapass(playerid, params[]) {
	UseAnim(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
	return true;
}

CMD:chat(playerid, params[]) {
	UseAnim(playerid,"PED","IDLE_CHAT",4.0,1,0,0,1,1);
	return true;
}

CMD:fucku(playerid, params[]) {
	UseAnim(playerid,"PED","fucku",4.0,0,0,0,0,0);
	return true;
}

CMD:taichi(playerid, params[]) {
	UseAnim(playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,0);
	return true;
}

CMD:injured(playerid, params[]) {
	UseAnim(playerid, "SWEET", "Sweet_injuredloop", 4.0,0,0,1,1,0);
	return true;
}

CMD:no(playerid, params[]) {
	UseAnim(playerid,"GANGS","Invite_No",4.0,0,0,0,0,0);
	return true;
}

CMD:yes(playerid, params[]) {
	UseAnim(playerid,"GANGS","Invite_Yes",4.0,0,0,0,0,0);
	return true;
}

CMD:crawl(playerid, params[]) {
	UseAnim(playerid,"PED","CAR_crawloutRHS",4.0,0,0,0,0,0);
	return true;
}

CMD:push(playerid, params[]) {
	UseAnim(playerid,"GANGS","shake_cara",4.0,0,0,0,0,0);
	return true;
}

CMD:akick(playerid) {
	UseAnim(playerid,"POLICE","Door_Kick",4.0,0,0,0,0,0);
	return true;
}

CMD:facepalm(playerid, params[]) {
	UseAnim(playerid,"MISC","plyr_shkhead",4.0,0,0,0,0,0);
	return true;
}

CMD:balls(playerid, params[]) {
	UseAnim(playerid,"MISC","scratchballs_01",4.0,0,0,0,0,0);
	return true;
}

CMD:lowbodypush(playerid, params[]) {
	UseAnim(playerid,"GANGS","shake_carSH",4.0,0,0,0,0,0);
	return true;
}

CMD:aspray(playerid, params[]) {
	UseAnim(playerid,"SPRAYCAN","spraycan_full",4.0,0,0,0,0,0);
	return true;
}

CMD:medic(playerid, params[]) {
	UseAnim(playerid,"MEDIC","CPR",4.0,0,0,0,0,0);
	return true;
}

CMD:koface(playerid, params[]) {
	UseAnim(playerid,"PED","KO_shot_face",4.0,0,1,1,1,0);
	return true;
}

CMD:kostomach(playerid, params[]) {
	UseAnim(playerid,"PED","KO_shot_stom",4.0,0,1,1,1,0);
	return true;
}

CMD:lifejump(playerid, params[]) {
	UseAnim(playerid,"PED","EV_dive",4.0,0,1,1,1,0);
	return true;
}

CMD:rollfall(playerid, params[]) {
	UseAnim(playerid,"PED","BIKE_fallR",4.0,0,1,1,1,0);
	return true;
}

CMD:hoodfrisked(playerid, params[]) {
	UseAnim(playerid,"POLICE","crm_drgbst_01",1.0,0,1,1,1,0);
	return true;
}

CMD:flip(playerid, params[]) {
	UseAnim(playerid,"PED","KD_left",4.1,0,1,1,1,0);
	return true;
}

CMD:box(playerid, params[]) {
	UseAnim(playerid,"GYMNASIUM","GYMshadowbox",4.0,1,1,1,1,0);
	return true;
}

CMD:chant(playerid, params[]) {
	UseAnim(playerid,"RIOT","RIOT_CHANT",4.0,1,1,1,1,0);
	return true;
}

CMD:finger(playerid, params[]) {
	UseAnim(playerid,"RIOT","RIOT_FUKU",2.0,0,0,0,0,0);
	return true;
}

CMD:gpunch(playerid, params[]) {
	UseAnim(playerid,"FIGHT_B","FightB_G",4.0,0,0,0,0,0);
	return true;
}

CMD:gkick(playerid, params[]) {
	UseAnim(playerid,"FIGHT_D","FightD_G",4.0,0,0,0,0,0);
	return true;
}

CMD:lowthrow(playerid, params[]) {
	UseAnim(playerid,"GRENADE","WEAPON_throwu",3.0,0,0,0,0,0);
	return true;
}

CMD:riot(playerid, params[]) {
	UseAnim(playerid,"RIOT","RIOT_ANGRY",4.0,0,0,0,0,0);
	return true;
}

CMD:abp(playerid, params[]) {
	UseAnim(playerid,"benchpress","gym_bp_celebrate",4.0,0,0,0,0,0);
	return true;
}

CMD:cry(playerid, params[]) {
	UseAnim(playerid,"GRAVEYARD","mrnF_loop",4.0,1,0,0,0,0);
	return true;
}

CMD:taxir(playerid, params[]) {
	UseAnim(playerid, "MISC","hiker_pose", 3.0,0,1,1,1,0);
	return true;
}

CMD:taxil(playerid, params[]) {
	UseAnim(playerid, "MISC","hiker_pose_L", 3.0,0,1,1,1,0);
	return true;
}

CMD:gro(playerid, params[]) {
	UseAnim(playerid,"BEACH", "ParkSit_M_loop", 4.0, 1, 0, 0, 0, 0);
	return true;
}

CMD:seat(playerid, params[]) {
	UseAnim(playerid,"INT_HOUSE","LOU_In",4.0,0,0,1,1,0);
	return true;
}

CMD:tatto(playerid, params[]) {
	UseAnim(playerid,"TATTOOS", "TAT_ArmR_Pose_P", 4.1, 0, 1, 1, 1, 0);
	return true;
}

CMD:waiml(playerid, params[]) {
	UseAnim(playerid,"PED","Driveby_L",4.1,0,1,1,1,1);
	return true;
}

CMD:waimr(playerid, params[]) {
	UseAnim(playerid,"PED","Driveby_R",4.1,0,1,1,1,1);
	return true;
}

CMD:caim(playerid, params[]) {
	UseAnim(playerid,"PED","IDLE_ROCKET",4.1,0,1,1,1,1);
	return true;
}

CMD:creep(playerid, params[]) {
	UseAnim(playerid,"PED","Player_Sneak",4.1,1,1,1,1,1);
	return true;
}

CMD:sroll(playerid, params[]) {
	UseAnim(playerid,"SWAT","JMP_Wall1m_180",4.1,0,1,1,1,0);
	return true;
}

CMD:gesture(playerid, params[]) {
	UseAnim(playerid,"SWAT","swt_lkt",4.0,0,0,0,0,0);
	return true;
}

CMD:lookoutr(playerid, params[]) {
	UseAnim(playerid,"SWAT","swt_wllpk_L",4.0,0,0,1,1,0);
	return true;
}

CMD:lookoutl(playerid, params[]) {
	UseAnim(playerid,"SWAT","swt_wllpk_R",4.0,0,0,1,1,0);
	return true;
}

CMD:agreement(playerid, params[]) {
	UseAnim(playerid,"COP_AMBIENT","Coplook_think",4.0,1,0,0,0,0);
	return true;
}

CMD:bend(playerid, params[]) {
	UseAnim(playerid,"BAR","Barserve_order",4.0,0,0,0,0,0);
	return true;
}

CMD:rod(playerid, params[]) {
	UseAnim(playerid,"benchpress","gym_bp_up_A",4.0,0,0,1,1,0);
	return true;
}

CMD:tgro(playerid, params[]) {
	UseAnim(playerid,"CAMERA","camcrch_cmon",4.0,0,0,1,1,0);
	return true;
}

CMD:cmouth(playerid, params[]) {
	UseAnim(playerid,"ON_LOOKERS","panic_in",4.0,0,0,1,1,0);
	return true;
}

CMD:gog(playerid, params[]) {
	UseAnim(playerid,"goggles","goggles_put_on",4.1,0,1,1,1,1);
	return true;
}

CMD:nfall(playerid, params[]) {
	UseAnim(playerid,"HEIST9","CAS_G2_GasKO",4.1,0,1,1,1,0);
	return true;
}

CMD:hsit(playerid, params[]) {
	UseAnim(playerid,"INT_OFFICE","OFF_Sit_Bored_Loop",4.0,1,0,1,1,0);
	return true;
}

CMD:csit(playerid, params[]) {
	UseAnim(playerid,"INT_OFFICE","OFF_Sit_Type_Loop",4.0,1,0,1,1,0);
	return true;
}

CMD:bracing(playerid, params[]) {
	UseAnim(playerid,"PLAYIDLES","stretch",4.0,0,0,0,0,0);
	return true;
}

CMD:pool(playerid, params[]) {
	UseAnim(playerid,"POOL","POOL_Long_Start",4.1,0,1,1,1,0);
	return true;
}

CMD:ssearch(playerid, params[]) {
	UseAnim(playerid,"ROB_BANK","CAT_Safe_Rob",4.0,1,0,0,0,0);
	return true;
}

CMD:daim(playerid, params[]) {
	UseAnim(playerid,"RYDER","Van_Stand_Crate",3.0,0,1,1,1,0);
	return true;
}

CMD:rhandl(playerid, params[]) {
	UseAnim(playerid,"SCRATCHING","scdlulp",4.0,0,0,1,1,0);
	return true;
}

CMD:rhandr(playerid, params[]) {
	UseAnim(playerid,"SCRATCHING","scdrulp",4.0,0,0,1,1,0);
	return true;
}

CMD:hstand(playerid, params[]) {
	UseAnim(playerid,"SCRATCHING","scdrdlp",4.0,0,0,1,1,0);
	return true;
}

CMD:nlean(playerid, params[]) {
	UseAnim(playerid,"SHAMAL","SHAMAL_align",4.1,0,1,1,1,0);
	return true;
}

CMD:shelter(playerid, params[]) {
	UseAnim(playerid,"SHOP","SHP_Duck_Fire",4.0,0,0,1,1,0);
	return true;
}

CMD:lookback(playerid, params[]) {
	UseAnim(playerid,"PED","flee_lkaround_01",4.0,0,0,0,0,0);
	return true;
}

CMD:wsit(playerid, params[]) {
	UseAnim(playerid,"SHOP","SHP_Gun_Duck",4.0,0,0,1,1,0);
	return true;
}

CMD:waim(playerid, params[]) {
	UseAnim(playerid,"TEC","TEC_reload",4.1,0,1,1,1,1);
	return true;
}

CMD:hangon(playerid, params[]) {
	UseAnim(playerid,"TRAIN","tran_ouch",4.0,0,0,1,1,0);
	return true;
}

CMD:sleepl(playerid, params[]) {
	UseAnim(playerid,"INT_HOUSE","BED_In_L",4.0,0,0,1,1,0);
	return true;
}

CMD:sleepr(playerid, params[]) {
	UseAnim(playerid,"INT_HOUSE","BED_In_R",4.0,0,0,1,1,0);
	return true;
}

CMD:blowj(playerid, params[]) {
	UseAnim(playerid,"BLOWJOBZ", "BJ_COUCH_START_W", 4.1, 0, 1, 1, 1, 0 );
	return true;
}

CMD:rseat(playerid, params[]) {
	UseAnim(playerid,"BLOWJOBZ", "BJ_COUCH_START_P", 4.1, 0, 1, 1, 1, 0 );
	return true;
}

CMD:polwalk(playerid, params[]) {
	UseAnim(playerid,"POLICE","Cop_move_FWD",3.0,1,1,1,1,1);
	return true;
}

CMD:nflip(playerid, params[]) {
	UseAnim(playerid,"PED","BIKE_fall_off",4.1,0,1,1,1,0);
	return true;
}

CMD:csdead(playerid, params[]) {
	UseAnim(playerid,"WUZI","CS_Dead_Guy",4.1,0,1,1,1,0);
	return true;
}

CMD:follow(playerid, params[]) {
	UseAnim(playerid,"WUZI","Wuzi_follow",4.1,0,1,1,1,1);
	return true;
}

CMD:grnd(playerid, params[]) {
	UseAnim(playerid,"WUZI","Wuzi_grnd_chk",4.0,0,0,0,0,0);
	return true;
}

CMD:copa(playerid, params[]) {
	UseAnim(playerid,"COP_AMBIENT","Copbrowse_in",4.1,0,1,1,1,0);
	return true;
}

CMD:cmon(playerid, params[]) {
	UseAnim(playerid,"OTB","wtchrace_cmon",4.1,0,1,1,1,0);
	return true;
}

CMD:lose(playerid, params[]) {
	UseAnim(playerid,"OTB","wtchrace_lose",4.1,0,1,1,1,0);
	return true;
}

CMD:win(playerid, params[]) {
	UseAnim(playerid,"OTB","wtchrace_win",4.1,0,1,1,1,0);
	return true;
}

CMD:gunthreat(playerid, params[]) {
	UseAnim(playerid,"SHOP","SHP_Gun_Threat",4.1,0,1,1,1,0);
	return true;
}

CMD:givecash(playerid, params[]) {
	UseAnim(playerid,"SHOP","SHP_Rob_GiveCash",4.1,0,1,1,1,0);
	return true;
}

CMD:robr(playerid, params[]) {
	UseAnim(playerid,"SHOP","SHP_Rob_React",4.1,0,1,1,1,0);
	return true;
}

CMD:serend(playerid, params[]) {
	UseAnim(playerid,"SHOP","SHP_Serve_End",4.1,0,1,1,1,0);
	return true;
}

CMD:heist(playerid, params[]) {
	UseAnim(playerid,"HEIST9","Use_SwipeCard",4.0,0,0,0,0,0);
	return true;
}

CMD:frontfall(playerid, params[]) {
	UseAnim(playerid,"PED","FLOOR_hit_f",4.1,0,1,1,1,0);
	return true;
}

CMD:pants(playerid, params[]) {
	UseAnim(playerid,"BLOWJOBZ","BJ_STAND_END_P",4.0,0,0,0,0,0);
	return true;
}
/////////////////////////////////////////////////////////////////////////
CMD:tired(playerid, params[]) {
	UseAnim(playerid,"FAT","IDLE_tired",4.0,0,0,1,1,0);
	return true;
}

CMD:climb(playerid, params[]) {
	UseAnim(playerid,"PED","CLIMB_jump",4.0,0,0,1,1,0);
	return true;
}

CMD:tlean(playerid, params[]) {
	UseAnim(playerid,"PED","DRIVE_BOAT",4.0,0,0,1,1,0);
	return true;
}

CMD:pushup(playerid, params[]) {
	UseAnim(playerid,"PED","getup_front",4.0,1,0,1,1,0);
	return true;
}

CMD:protection(playerid, params[]) {
	UseAnim(playerid,"PED","FightShB",4.0,0,1,1,1,1);
	return true;
}

CMD:swallow(playerid, params[]) {
	UseAnim(playerid,"PED","gum_eat",4.0,0,0,0,0,0);
	return true;
}

CMD:stand(playerid, params[]) {
	UseAnim(playerid,"PED","IDLE_HBHB",3.0,0,1,1,1,0);
	return true;
}

CMD:pullhand(playerid, params[]) {
	UseAnim(playerid,"PED","Jetpack_Idle",3.0,0,1,1,1,0);
	return true;
}

CMD:nlook(playerid, params[]) {
	UseAnim(playerid,"PED","roadcross_gang",4.0,0,0,0,0,0);
	return true;
}

CMD:extend(playerid, params[]) {
	UseAnim(playerid,"PED","Shove_Partial",4.1,0,1,1,1,1);
	return true;
}

CMD:stopit(playerid, params[]) {
	UseAnim(playerid,"PED","Walk_DoorPartial",4.0,0,0,0,0,0);
	return true;
}

CMD:ksit(playerid, params[]) {
	UseAnim(playerid,"INT_OFFICE","OFF_Sit_Crash",4.0,1,0,1,1,0);
	return true;
}

CMD:esit(playerid, params[]) {
	UseAnim(playerid,"INT_OFFICE","OFF_Sit_Drink",4.0,1,0,1,1,0);
	return true;
}

CMD:tsit(playerid, params[]) {
	UseAnim(playerid,"INT_OFFICE","OFF_Sit_Watch",4.0,0,0,1,1,0);
	return true;
}

CMD:rtake(playerid, params[]) {
	UseAnim(playerid,"BAR","Barserve_give",4.0,0,0,0,0,0);
	return true;
}

CMD:forwardlook(playerid, params[]) {
	UseAnim(playerid,"BD_FIRE","BD_Panic_02",4.1,0,1,1,1,0);
	return true;
}

CMD:wforwardlook(playerid, params[]) {
	UseAnim(playerid,"BD_FIRE","BD_Panic_03",4.1,0,1,1,1,0);
	return true;
}

CMD:taction(playerid, params[]) {
	UseAnim(playerid,"BD_FIRE","wash_up",4.0,0,0,0,0,0);
	return true;
}

CMD:catch(playerid, params[]) {
	UseAnim(playerid,"MD_CHASE","MD_HANG_Loop",4.1,0,1,1,1,0);
	return true;
}

CMD:despair(playerid, params[]) {
	UseAnim(playerid,"BSKTBALL","BBALL_react_miss",4.0,0,0,0,0,0);
	return true;
}

CMD:rooting(playerid, params[]) {
	UseAnim(playerid,"BSKTBALL","BBALL_react_score",4.1,1,1,1,1,0);
	return true;
}

CMD:spyglass(playerid, params[]) {
	UseAnim(playerid,"CAMERA","picstnd_take",4.1,0,1,1,1,0);
	return true;
}

CMD:looksky(playerid, params[]) {
	UseAnim(playerid,"ON_LOOKERS","lkup_loop",4.1,0,1,1,1,0);
	return true;
}

CMD:mshow(playerid, params[]) {
	UseAnim(playerid,"ON_LOOKERS","panic_point",4.1,0,1,1,1,0);
	return true;
}

CMD:wshow(playerid, params[]) {
	UseAnim(playerid,"ON_LOOKERS","panic_shout",4.1,0,1,1,1,0);
	return true;
}

CMD:hshow(playerid, params[]) {
	UseAnim(playerid,"ON_LOOKERS","point_loop",4.1,0,1,1,1,0);
	return true;
}

CMD:sh(playerid, params[]) {
	UseAnim(playerid,"ON_LOOKERS","shout_in",4.0,0,0,0,0,0);
	return true;
}

CMD:crossfingers(playerid, params[]) {
	UseAnim(playerid,"CASINO","cards_loop",4.1,0,1,1,1,0);
	return true;
}

CMD:delight(playerid, params[]) {
	UseAnim(playerid,"CASINO","manwinb",4.0,0,0,0,0,0);
	return true;
}

CMD:hdelight(playerid, params[]) {
	UseAnim(playerid,"CASINO","manwind",4.0,0,0,0,0,0);
	return true;
}

CMD:showtable(playerid, params[]) {
	UseAnim(playerid,"CASINO","Roulette_bet",4.1,0,1,1,1,0);
	return true;
}

CMD:tfacepalm(playerid, params[]) {
	UseAnim(playerid,"CASINO","Roulette_lose",4.1,0,1,1,1,0);
	return true;
}

CMD:tpull(playerid, params[]) {
	UseAnim(playerid,"CASINO","Slot_in",4.1,0,1,1,1,0);
	return true;
}

CMD:fail(playerid, params[]) {
	UseAnim(playerid,"CASINO","Slot_lose_out",4.0,0,0,0,0,0);
	return true;
}

CMD:joy(playerid, params[]) {
	UseAnim(playerid,"CASINO","Slot_win_out",4.0,0,0,0,0,0);
	return true;
}

CMD:wear(playerid, params[]) {
	UseAnim(playerid,"CARRY","crry_prtial",4.1,0,1,1,1,1);
	return true;
}

CMD:fsit(playerid, params[]) {
	UseAnim(playerid,"JST_BUISNESS","girl_02",4.1,0,1,1,1,0);
	return true;
}

CMD:crushjump(playerid, params[]) {
	UseAnim(playerid,"DODGE","Crush_Jump",4.1,0,1,1,1,0);
	return true;
}

CMD:scatch(playerid, params[]) {
	UseAnim(playerid,"FINALE","FIN_LegsUp_Loop",4.1,0,1,1,1,0);
	return true;
}

CMD:lookfloor(playerid, params[]) {
	UseAnim(playerid,"FINALE","FIN_Cop1_Loop",4.1,0,1,1,1,0);
	return true;
}

CMD:tramplefloor(playerid, params[]) {
	UseAnim(playerid,"FINALE","FIN_Cop1_Stomp",4.1,1,1,1,1,0);
	return true;
}

CMD:swing(playerid, params[]) {
	UseAnim(playerid,"Freeweights","gym_free_B",4.1,0,1,1,1,0);
	return true;
}

CMD:nbp(playerid, params[]) {
	UseAnim(playerid,"Freeweights","gym_free_celebrate",4.0,0,0,0,0,0);
	return true;
}

CMD:takehead(playerid, params[]) {
	UseAnim(playerid,"HAIRCUTS","BRB_Cut",4.1,0,1,1,1,0);
	return true;
}

CMD:readtable(playerid, params[]) {
	UseAnim(playerid,"SCRATCHING","sclng_r",4.1,0,1,1,1,0);
	return true;
}

CMD:squat(playerid, params[]) {
	UseAnim(playerid,"TEC","TEC_crouchfire",4.1,0,1,1,1,0);
	return true;
}

CMD:sprawl(playerid, params[]) {
	UseAnim(playerid,"TATTOOS","TAT_Idle_Loop_T",4.1,0,1,1,1,0);
	return true;
}

CMD:throwmoney(playerid, params[]) {
	UseAnim(playerid,"STRIP","PUN_CASH",4.0,0,0,0,0,0);
	return true;
}

CMD:sho(playerid, params[]) {
	UseAnim(playerid,"STRIP","PUN_HOLLER",4.0,0,0,0,0,0);
	return true;
}

CMD:faim(playerid, params[]) {
	UseAnim(playerid,"SWORD","sword_IDLE",4.1,0,1,1,1,0);
	return true;
}

CMD:piss(playerid, params[]) {
	UseAnim(playerid,"PAULNMAC","Piss_in",4.1,0,1,1,1,0);
	return true;
}

CMD:swingback(playerid, params[]) {
	UseAnim(playerid,"PED","getup",4.1,1,1,1,1,0);
	return true;
}

CMD:onehand(playerid, params[]) {
	UseAnim(playerid,"PED","CLIMB_jump2fall",4.1,0,1,1,1,0);
	return true;
}

CMD:backwalk(playerid, params[]) {
	UseAnim(playerid,"PED","gas_cwr",4.1,1,1,1,1,1);
	return true;
}

CMD:feettog(playerid, params[]) {
	UseAnim(playerid,"PED","Idlestance_fat",4.1,0,1,1,1,0);
	return true;
}

CMD:mirro(playerid, params[]) {
	UseAnim(playerid,"CLOTHES","CLO_Pose_Hat",4.1,0,1,1,1,0);
	return true;
}

CMD:hips(playerid, params[]) {
	UseAnim(playerid,"COP_AMBIENT","Coplook_shake",4.1,0,1,1,1,0);
	return true;
}

CMD:pullo(playerid, params[]) {
	UseAnim(playerid,"AIRPORT","thrw_barl_thrw",4.1,0,1,1,1,0);
	return true;
}

CMD:obalance(playerid, params[]) {
	UseAnim(playerid,"BD_FIRE","BD_Panic_02",4.1,0,1,1,1,0);
	return true;
}

CMD:wobalance(playerid, params[]) {
	UseAnim(playerid,"BD_FIRE","BD_Panic_03",4.1,0,1,1,1,0);
	return true;
}

CMD:dance(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1, "Используйте: /dance [1-12]");
	switch(params[0]) {
		case 1 : SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
		case 2 : SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
		case 3 : SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
		case 4 : SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
		case 5 : UseAnim(playerid,"DANCING","bd_clap",4.1,1,1,1,1,1);
		case 6 : UseAnim(playerid,"DANCING","bd_clap1",4.1,1,1,1,1,1);
		case 7 : UseAnim(playerid,"DANCING","DAN_Down_A",4.1,1,1,1,1,1);
		case 8 : UseAnim(playerid,"DANCING","DAN_Left_A",4.1,1,1,1,1,1);
		case 9 : UseAnim(playerid,"DANCING","DAN_Loop_A",4.1,1,1,1,1,1);
		case 10 : UseAnim(playerid,"DANCING","DAN_Right_A",4.1,1,1,1,1,1);
		case 11 : UseAnim(playerid,"DANCING","DAN_Up_A",4.1,1,1,1,1,1);
		case 12 : UseAnim(playerid,"DANCING","dnce_M_a",4.1,1,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /dance [1-12]");
	}
	return true;
}

CMD:repcar(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /repcar [1-2]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"CAR","Fixn_Car_Loop",3.0,0,1,1,1,0);
		case 2 : UseAnim(playerid,"CAR","Fixn_Car_Out",3.0,0,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /repcar [1-2]");
	}
	return true;
}


CMD:hnds(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /hnds [1-7]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"LOWRIDER","prtial_gngtlkB",4.1,0,1,1,1,1);
		case 2 : UseAnim(playerid,"LOWRIDER","prtial_gngtlkC",4.1,0,1,1,1,1);
		case 3 : UseAnim(playerid,"LOWRIDER","prtial_gngtlkD",4.1,0,1,1,1,1);
		case 4 : UseAnim(playerid,"LOWRIDER","prtial_gngtlkE",4.1,0,1,1,1,1);
		case 5 : UseAnim(playerid,"LOWRIDER","prtial_gngtlkF",4.1,0,1,1,1,1);
		case 6 : UseAnim(playerid,"LOWRIDER","prtial_gngtlkG",4.1,0,1,1,1,1);
		case 7 : UseAnim(playerid,"LOWRIDER","prtial_gngtlkH",4.1,0,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /hnds [1-7]");
	}
	return true;
}

CMD:strip(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /strip [1-14]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"STRIP", "strip_A", 4.1, 1, 1, 1, 1, 1 );
		case 2 : UseAnim(playerid,"STRIP", "strip_B", 4.1, 1, 1, 1, 1, 1 );
		case 3 : UseAnim(playerid,"STRIP", "strip_C", 4.1, 1, 1, 1, 1, 1 );
		case 4 : UseAnim(playerid,"STRIP", "strip_D", 4.1, 1, 1, 1, 1, 1 );
		case 5 : UseAnim(playerid,"STRIP", "strip_E", 4.1, 1, 1, 1, 1, 1 );
		case 6 : UseAnim(playerid,"STRIP", "strip_F", 4.1, 1, 1, 1, 1, 1 );
		case 7 : UseAnim(playerid,"STRIP", "strip_G", 4.1, 1, 1, 1, 1, 1 );
     	case 8: ApplyAnimation(playerid,"STRIP","STR_A2B",4.1,1,1,1,1,1);
        case 9: ApplyAnimation(playerid,"STRIP","STR_B2C",4.1,1,1,1,1,1);
        case 10: ApplyAnimation(playerid,"STRIP","STR_C1",4.1,1,1,1,1,1);
        case 11: ApplyAnimation(playerid,"STRIP","STR_C2",4.1,1,1,1,1,1);
        case 12: ApplyAnimation(playerid,"STRIP","STR_Loop_A",4.1,1,1,1,1,1);
        case 13: ApplyAnimation(playerid,"STRIP","STR_Loop_B",4.1,1,1,1,1,1);
        case 14: ApplyAnimation(playerid,"STRIP","STR_Loop_C",4.1,1,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /strip [1-14]");
	}
	return true;
}


CMD:deal(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /deal [1-3]");
	switch(params[0]) {
		case 1 : UseAnim(playerid, "DEALER", "DEALER_DEAL", 4.0, 0, 0, 0, 0, 0);
		case 2 : UseAnim(playerid, "DEALER","DEALER_IDLE", 3.0,0,1,1,1,0);
		case 3 : UseAnim(playerid,"GRAVEYARD","mrnM_loop",3.0,0,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /deal [1-3]");
	}
	return true;
}

CMD:asmoke(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /asmoke [1-4]");
	switch(params[0]) {
		case 1 : UseAnim(playerid, "SMOKING", "M_smklean_loop", 4.0, 1, 0, 0, 0, 0);
		case 2 : UseAnim(playerid, "SMOKING", "F_smklean_loop", 4.0, 1, 0, 0, 0, 0);
		case 3 : UseAnim(playerid, "SMOKING","M_smkstnd_loop", 4.0, 1, 0, 0, 0, 0);
		case 4 : UseAnim(playerid, "SMOKING","M_smk_out", 4.0, 0, 0, 0, 0, 0);
		default : SCM( playerid, -1,   "Используйте: /asmoke [1-4]");
	}
	return true;
}

CMD:rap(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /rap [1-9]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"RAPPING","RAP_A_Loop",4.0,1,0,0,0,0);
		case 2 : UseAnim(playerid,"RAPPING","RAP_C_Loop",4.0,1,0,0,0,0);
		case 3 : UseAnim(playerid,"GANGS","prtial_gngtlkD",4.0,1,0,0,1,1);
		case 4 : UseAnim(playerid,"GANGS","prtial_gngtlkH",4.0,1,0,0,1,1);
		case 5 : UseAnim(playerid,"GANGS","prtial_gngtlkF",4.0,1,0,0,1,1);
		case 6 : UseAnim(playerid,"GANGS","prtial_gngtlkG",4.0,1,0,0,1,1);
		case 7 : UseAnim(playerid,"PED","ATM",4.0,0,0,0,0,0);
		case 8 : UseAnim(playerid,"RAPPING","RAP_B_IN",3.0,0,1,1,1,0);
		case 9 : UseAnim(playerid,"GYMNASIUM","gym_tread_celebrate",4.1,0,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /rap [1-9]");
	}
	return true;
}

CMD:bat(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /bat [1-2]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"CRACK","Bbalbat_Idle_02",4.0, 1, 0, 0, 0, 0);
		case 2 : UseAnim(playerid,"CRACK","Bbalbat_Idle_01",4.0, 1, 0, 0, 0, 0);
		default : SCM( playerid, -1,   "Используйте: /bat [1-2]");
	}
	return true;
}

CMD:basket(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /basket [1-6]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"BSKTBALL","BBALL_idleloop",4.0,1,0,0,0,0);
		case 2 : UseAnim(playerid,"BSKTBALL","BBALL_Jump_Shot",4.0,0,0,0,0,0);
		case 3 : UseAnim(playerid,"BSKTBALL","BBALL_pickup",4.0,0,0,0,0,0);
		case 4 : UseAnim(playerid,"BSKTBALL","BBALL_run",4.1,1,1,1,1,1);
		case 5 : UseAnim(playerid,"BSKTBALL","BBALL_def_loop",4.0,1,0,0,0,0);
		case 6 : UseAnim(playerid,"BSKTBALL","BBALL_Dnk",4.0,0,0,0,0,0);
		default : SCM( playerid, -1,   "Используйте: /basket [1-6]");
	}
	return true;
}

CMD:lean(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /lean [1-3]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"GANGS","leanIDLE",4.0,0,0,1,1,0);
		case 2 : UseAnim(playerid,"MISC","Plyrlean_loop",4.0,0,1,1,1,0);
		case 3 : UseAnim(playerid,"CAR_CHAT","car_talkm_loop",4.0,0,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /lean [1-3]");
	}
	return true;
}

CMD:lay(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /lay [1-5]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"BEACH", "bather", 4.0, 1, 0, 0, 0, 0);
		case 2 : UseAnim(playerid,"SUNBATHE","Lay_Bac_in",3.0,0,1,1,1,0);
		case 3 : UseAnim(playerid,"BEACH","ParkSit_W_loop",3.0,0,1,1,1,0);
		case 4 : UseAnim(playerid,"BEACH","SitnWait_loop_W",4.0, 1, 0, 0, 0, 0);
		case 5 : UseAnim(playerid,"SUNBATHE","SBATHE_F_LieB2Sit",3.0,0,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /lay [1-5]");
	}
	return true;
}

CMD:gsign(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /gsign [1-10]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"GHANDS","gsign1",4.1,0,1,1,1,1);
		case 2 : UseAnim(playerid,"GHANDS","gsign1LH",4.1,0,1,1,1,1);
		case 3 : UseAnim(playerid,"GHANDS","gsign2",4.1,0,1,1,1,1);
		case 4 : UseAnim(playerid,"GHANDS","gsign2LH",4.1,0,1,1,1,1);
		case 5 : UseAnim(playerid,"GHANDS","gsign3",4.1,0,1,1,1,1);
		case 6 : UseAnim(playerid,"GHANDS","gsign3LH",4.1,0,1,1,1,1);
		case 7 : UseAnim(playerid,"GHANDS","gsign4",4.1,0,1,1,1,1);
		case 8 : UseAnim(playerid,"GHANDS","gsign4LH",4.1,0,1,1,1,1);
		case 9 : UseAnim(playerid,"GHANDS","gsign5",4.1,0,1,1,1,1);
		case 10 : UseAnim(playerid,"GHANDS","gsign5LH",4.1,0,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /gsign [1-10]");
	}
	return true;
}

CMD:walk(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /walk [1-12]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"PED","WALK_player",4.1,1,1,1,1,1);
		case 2 : UseAnim(playerid,"PED","WOMAN_walkbusy",4.1,1,1,1,1,1);
		case 3 : UseAnim(playerid,"PED","WOMAN_walkfatold",4.1,1,1,1,1,1);
		case 4 : UseAnim(playerid,"PED","WOMAN_walkpro",4.1,1,1,1,1,1);
		case 5 : UseAnim(playerid,"PED","WALK_gang1",4.1,1,1,1,1,1);
		case 6 : UseAnim(playerid,"PED","WALK_gang2",4.1,1,1,1,1,1);
		case 7 : UseAnim(playerid,"PED","WALK_civi",4.1,1,1,1,1,1);
		case 8 : UseAnim(playerid,"PED","Walk_Wuzi",4.1,1,1,1,1,1);
		case 9 : UseAnim(playerid,"PED","WALK_armed",4.1,1,1,1,1,1);
		case 10 : UseAnim(playerid,"PED","WALK_old",4.1,1,1,1,1,1);
		case 11 : UseAnim(playerid,"PED","WALK_drunk",4.1,1,1,1,1,1);
		case 12 : UseAnim(playerid,"WUZI","Wuzi_Walk",4.1,1,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /walk [1-12]");
	}
	return true;
}

CMD:wave(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /wave [1-4]");
	switch(params[0]) {
		case 1 : UseAnim(playerid, "KISSING","gfwave2", 4.1,0,1,1,0,0);
		case 2 : UseAnim(playerid, "ON_LOOKERS","wave_loop", 4.1,1,1,1,0,0);
		case 3 : UseAnim(playerid,"CAMERA","camstnd_cmon",4.0,0,0,0,0,0);
		case 4 : UseAnim(playerid,"PED","endchat_01",4.1,0,1,1,0,0);
		default : SCM( playerid, -1,   "Используйте: /wave [1-4]");
	}
	return true;
}

CMD:police(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /police [1-4]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"POLICE","CopTraf_Away",3.0,1,0,0,1,0);
		case 2 : UseAnim(playerid,"POLICE","CopTraf_Come",3.0,1,0,0,1,0);
		case 3 : UseAnim(playerid,"POLICE","CopTraf_Left",3.0,1,0,0,1,0);
		case 4 : UseAnim(playerid,"POLICE","CopTraf_Stop",3.0,1,0,0,1,0);
		default : SCM( playerid, -1,   "Используйте: /police [1-4]");
	}
	return true;
}

CMD:crack(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /crack [1-7]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"CRACK","crckdeth2",3.0,1,1,1,1,0);
		case 2 : UseAnim(playerid,"CRACK","crckdeth4",3.0,0,1,1,1,0);
		case 3 : UseAnim(playerid,"CRACK","crckidle1",3.0,0,1,1,1,0);
		case 4 : UseAnim(playerid,"CRACK","crckidle2",3.0,0,1,1,1,0);
		case 5 : UseAnim(playerid,"CRACK","crckidle3",3.0,0,1,1,1,0);
		case 6 : UseAnim(playerid,"CRACK","crckdeth1",3.0,0,1,1,1,0);
		case 7 : UseAnim(playerid,"CRACK","crckdeth3",3.0,0,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /crack [1-7]");
	}
	return true;
}

CMD:car(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /car [1-11]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"LOWRIDER","lrgirl_bdbnce",4.1,0,1,1,1,0);
		case 2 : UseAnim(playerid,"LOWRIDER","lrgirl_hair",4.1,0,1,1,1,0);
		case 3 : UseAnim(playerid,"LOWRIDER","lrgirl_idle_to_l0",4.1,0,1,1,1,0);
		case 4 : UseAnim(playerid,"PED","Tap_hand",4.1,0,1,1,1,0);
		case 5 : UseAnim(playerid,"PED","Tap_handP",4.1,0,1,1,1,0);
		case 6 : UseAnim(playerid,"LOWRIDER","lrgirl_l12_to_l0",4.1,0,1,1,1,0);
		case 7 : UseAnim(playerid,"LOWRIDER","lrgirl_l2_to_l3",4.1,0,1,1,1,0);
		case 8 : UseAnim(playerid,"PED","CAR_LB",4.1,0,1,1,1,0);
		case 9 : UseAnim(playerid,"PED","CAR_sitp",4.1,0,1,1,1,0);
		case 10 : UseAnim(playerid,"PED","CAR_sitpLO",4.1,0,1,1,1,0);
		case 11 : UseAnim(playerid,"CAR_CHAT","carfone_loopA",4.1,1,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /car [1-11]");
	}
	return true;
}

CMD:wallow(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /wallow [1-2]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll",4.1,0,1,1,1,0);
		case 2 : UseAnim(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll_F",4.1,0,1,1,1,0);
		default : SCM( playerid, -1,   "Используйте: /wallow [1-2]");
	}
	return true;
}

CMD:beckon(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /beckon [1-3]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"RYDER","RYD_Beckon_01",4.1,0,1,1,1,1);
		case 2 : UseAnim(playerid,"RYDER","RYD_Beckon_02",4.1,0,1,1,1,1);
		case 3 : UseAnim(playerid,"RYDER","RYD_Beckon_03",4.1,0,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /beckon [1-3]");
	}
	return true;
}

CMD:shotgun(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /shotgun [1-3]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"SHOTGUN","shotgun_crouchfire",4.1,0,1,1,1,1);
		case 2 : UseAnim(playerid,"SHOTGUN","shotgun_fire",4.1,0,1,1,1,1);
		case 3 : UseAnim(playerid,"SHOTGUN","shotgun_fire_poor",4.1,0,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /shotgun [1-3]");
	}
	return true;
}

CMD:colt(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /colt [1-3]");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"COLT45","colt45_fire_2hands",4.1,0,1,1,1,1);
		case 2 : UseAnim(playerid,"COLT45","colt45_reload",4.1,0,1,1,1,1);
		case 3 : UseAnim(playerid,"COLT45","sawnoff_reload",4.1,0,1,1,1,1);
		default : SCM( playerid, -1,   "Используйте: /colt [1-3]");
	}
	return true;
}

CMD:dps(playerid, params[]) {

	if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Введите: /dps [1-2] Введите: /dps [1-2] | (1 - Руки за спину | 2 - Остановка авто жезлом.)");
	switch(params[0]) {
		case 1 : UseAnim(playerid,"COLT45","colt45_fire_2hands",4.1,0,1,1,1,1);
		case 2 : UseAnim(playerid, "COP_AMBIENT", "Coplook_loop", 4.0, 0, 1, 1, 1, -1);
		default : SCM( playerid, -1,   "Введите: /dps [1-2] Введите: /dps [1-2] | (1 - Руки за спину | 2 - Остановка авто жезлом.)");
	}
	return true;
}

CMD:animka(playerid, params[]) {

    if(sscanf(params, "d", params[0])) return SCM( playerid, -1,   "Используйте: /animka");
    switch(params[0]) {
        case 1 : ApplyAnimation(playerid, "Anim_Reg", "metla", 4.1, 0, 1, 1, 1, 1, 1);
        case 2 : ApplyAnimation(playerid, "Animation_GTRP", "valik", 4.1, 0, 1, 1, 1, 1, 1);
        case 3 : ApplyAnimation(playerid, "Animation_GTRP", "nozn01", 4.1, 0, 1, 1, 1, 1, 1);
        case 4 : ApplyAnimation(playerid, "Animation_GTRP", "racia", 4.1, 0, 1, 1, 1, 1, 1);
        case 5 : ApplyAnimation(playerid, "Animation_GTRP", "shvabr", 4.1, 0, 1, 1, 1, 1, 1);
        case 6 : ApplyAnimation(playerid, "Animation_GTRP", "chest01", 4.1, 0, 1, 1, 1, 1, 1);
        case 7 : ApplyAnimation(playerid, "Animation_GTRP", "chest02", 4.1, 0, 1, 1, 1, 1, 1);
        case 8 : ApplyAnimation(playerid, "Animation_GTRP", "smirno", 4.1, 0, 1, 1, 1, 1, 1);
        case 9 : ApplyAnimation(playerid, "Animation_GTRP", "dpsstop", 4.1, 0, 1, 1, 1, 1, 1);
        case 10 : ApplyAnimation(playerid, "Animation_GTRP", "kobura", 4.1, 0, 1, 1, 1, 1, 1);
        case 11 : ApplyAnimation(playerid, "Animation_GTRP", "leg", 4.1, 0, 1, 1, 1, 1, 1);
        case 12 : ApplyAnimation(playerid, "Animation_GTRP", "zezl01", 4.1, 0, 1, 1, 1, 1, 1);
        case 13 : ApplyAnimation(playerid, "Animation_GTRP", "zezl02", 4.1, 0, 1, 1, 1, 1, 1);
        case 14 : ApplyAnimation(playerid, "Animation_GTRP", "zezl03", 4.1, 0, 1, 1, 1, 1, 1);
        case 15 : ApplyAnimation(playerid, "Animation_GTRP", "shit01", 4.1, 0, 1, 1, 1, 1, 1);
        case 16 : ApplyAnimation(playerid, "Animation_GTRP", "shit02", 4.1, 0, 1, 1, 1, 1, 1);
        case 17 : ApplyAnimation(playerid, "Animation_GTRP", "leg02", 4.1, 0, 1, 1, 1, 1, 1);
        case 18 : ApplyAnimation(playerid, "Animation_GTRP", "chest03", 4.1, 0, 1, 1, 1, 1, 1);
        case 19 : ApplyAnimation(playerid, "Animation_GTRP", "molot", 4.1, 0, 1, 1, 1, 1, 1);
        case 20 : ApplyAnimation(playerid, "Animation_GTRP", "lopata", 4.1, 0, 1, 1, 1, 1, 1);
        case 21 : ApplyAnimation(playerid, "Animation_GTRP", "electric", 4.1, 0, 1, 1, 1, 1, 1);
        case 22 : ApplyAnimation(playerid, "Animation_GTRP", "lopata2", 4.1, 0, 1, 1, 1, 1, 1);
        case 23 : ApplyAnimation(playerid, "Animation_GTRP", "lopata3", 4.1, 0, 1, 1, 1, 1, 1);
        case 24 : ApplyAnimation(playerid, "Animation_GTRP", "otjim1", 4.1, 0, 1, 1, 1, 1, 1);
        case 25 : ApplyAnimation(playerid, "Animation_GTRP", "otjim2", 4.1, 0, 1, 1, 1, 1, 1);
        case 27 : ApplyAnimation(playerid, "Animation_GTRP", "otjim3", 4.1, 0, 1, 1, 1, 1, 1);
        case 28 : ApplyAnimation(playerid, "Animation_GTRP", "otjim4", 4.1, 0, 1, 1, 1, 1, 1);
        case 29 : ApplyAnimation(playerid, "Animation_GTRP", "test_anim", 4.1, 0, 1, 1, 1, 1, 1);
        case 30 : ApplyAnimation(playerid, "Animation_GTRP", "brysla01", 4.1, 0, 1, 1, 1, 1, 1);
        case 31 : ApplyAnimation(playerid, "Animation_GTRP", "brysla02", 4.1, 0, 1, 1, 1, 1, 1);
        case 32 : ApplyAnimation(playerid, "Animation_GTRP", "brysla03", 4.1, 0, 1, 1, 1, 1, 1);
        case 33 : ApplyAnimation(playerid, "Animation_GTRP", "brysla04", 4.1, 0, 1, 1, 1, 1, 1);
        case 34 : ApplyAnimation(playerid, "Animation_GTRP", "otjimtyr01", 4.1, 0, 1, 1, 1, 1, 1);
        case 35 : ApplyAnimation(playerid, "Animation_GTRP", "otjimtyr02", 4.1, 0, 1, 1, 1, 1, 1);
        case 36 : ApplyAnimation(playerid, "Animation_GTRP", "otjimtyr03", 4.1, 0, 1, 1, 1, 1, 1);
        case 37 : ApplyAnimation(playerid, "Animation_GTRP", "otjimtyr04", 4.1, 0, 1, 1, 1, 1, 1);
        case 38 : ApplyAnimation(playerid, "Animation_GTRP", "press01", 4.1, 0, 1, 1, 1, 1, 1);
        case 39 : ApplyAnimation(playerid, "Animation_GTRP", "press02", 4.1, 0, 1, 1, 1, 1, 1);
        case 40 : ApplyAnimation(playerid, "Animation_GTRP", "press03", 4.1, 0, 1, 1, 1, 1, 1);
        case 41 : ApplyAnimation(playerid, "Animation_GTRP", "press04", 4.1, 0, 1, 1, 1, 1, 1);
        case 42 : ApplyAnimation(playerid, "Animation_GTRP", "presspol01", 4.1, 0, 1, 1, 1, 1, 1);
        default : SCM( playerid, -1,   "Используйте: /animka");
    }
    return true;
}

CMD:sit(playerid, params[])
{
    switch (strval(params)) 
    {
        case 1: UseAnim(playerid, "CRIB", "PED_Console_Loop", 4.1, 1, 0, 0, 0, 0, 1);
        case 2: UseAnim(playerid, "INT_HOUSE", "LOU_In", 4.1, 0, 0, 0, 1, 0, 1);
        case 3: UseAnim(playerid, "MISC", "SEAT_LR", 4.1, 1, 0, 0, 0, 0, 1);
        case 4: UseAnim(playerid, "MISC", "Seat_talk_01", 4.1, 1, 0, 0, 0, 0, 1);
        case 5: UseAnim(playerid, "MISC", "Seat_talk_02", 4.1, 1, 0, 0, 0, 0, 1);
        case 6: UseAnim(playerid, "ped", "SEAT_down", 4.1, 0, 0, 0, 1, 0, 1);
        default:
        {
            SCM(playerid, -1, "Используйте: /sit [1-6]"); 
        }
    }
    return 1;
} 