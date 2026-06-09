new Text:drawtaxi[13][MAX_PLAYERS];

stock textdrawtaxi(playerid,show,create,hide,del,dopshow,dophide)
{
if(create==1)
{
drawtaxi[0][playerid] = TextDrawCreate(403.000000, 382.000000, "_");
TextDrawAlignment(drawtaxi[0][playerid], 2);
TextDrawBackgroundColor(drawtaxi[0][playerid], 255);
TextDrawFont(drawtaxi[0][playerid], 1);
TextDrawLetterSize(drawtaxi[0][playerid], 1.030000, 3.399999);
TextDrawColor(drawtaxi[0][playerid], -1);
TextDrawSetOutline(drawtaxi[0][playerid], 0);
TextDrawSetProportional(drawtaxi[0][playerid], 1);
TextDrawSetShadow(drawtaxi[0][playerid], 1);
TextDrawUseBox(drawtaxi[0][playerid], 1);
TextDrawBoxColor(drawtaxi[0][playerid], 255);
TextDrawTextSize(drawtaxi[0][playerid], 46.000000, -124.000000);

drawtaxi[1][playerid] = TextDrawCreate(355.000000, 365.000000, "‹‘?O‹‘:");
TextDrawBackgroundColor(drawtaxi[1][playerid], 255);
TextDrawFont(drawtaxi[1][playerid], 2);
TextDrawLetterSize(drawtaxi[1][playerid], 0.380000, 1.100000);
TextDrawColor(drawtaxi[1][playerid], 411893759);
TextDrawSetOutline(drawtaxi[1][playerid], 0);
TextDrawSetProportional(drawtaxi[1][playerid], 1);
TextDrawSetShadow(drawtaxi[1][playerid], 1);

drawtaxi[2][playerid] = TextDrawCreate(439.000000, 365.000000, "12");
TextDrawAlignment(drawtaxi[2][playerid], 2);
TextDrawBackgroundColor(drawtaxi[2][playerid], 255);
TextDrawFont(drawtaxi[2][playerid], 2);
TextDrawLetterSize(drawtaxi[2][playerid], 0.380000, 1.100000);
TextDrawColor(drawtaxi[2][playerid], -1);
TextDrawSetOutline(drawtaxi[2][playerid], 0);
TextDrawSetProportional(drawtaxi[2][playerid], 1);
TextDrawSetShadow(drawtaxi[2][playerid], 1);

drawtaxi[3][playerid] = TextDrawCreate(403.000000, 386.000000, "?AP…?…KA‰…•:");
TextDrawAlignment(drawtaxi[3][playerid], 2);
TextDrawBackgroundColor(drawtaxi[3][playerid], 255);
TextDrawFont(drawtaxi[3][playerid], 2);
TextDrawLetterSize(drawtaxi[3][playerid], 0.380000, 1.100000);
TextDrawColor(drawtaxi[3][playerid], 411893759);
TextDrawSetOutline(drawtaxi[3][playerid], 0);
TextDrawSetProportional(drawtaxi[3][playerid], 1);
TextDrawSetShadow(drawtaxi[3][playerid], 1);

drawtaxi[4][playerid] = TextDrawCreate(403.000000, 398.000000, "II A?AIAIE");
TextDrawAlignment(drawtaxi[4][playerid], 2);
TextDrawBackgroundColor(drawtaxi[4][playerid], 255);
TextDrawFont(drawtaxi[4][playerid], 2);
TextDrawLetterSize(drawtaxi[4][playerid], 0.330000, 1.200000);
TextDrawColor(drawtaxi[4][playerid], -1);
TextDrawSetOutline(drawtaxi[4][playerid], 0);
TextDrawSetProportional(drawtaxi[4][playerid], 1);
TextDrawSetShadow(drawtaxi[4][playerid], 1);

drawtaxi[5][playerid] = TextDrawCreate(403.000000, 363.000000, "_");
TextDrawAlignment(drawtaxi[5][playerid], 2);
TextDrawBackgroundColor(drawtaxi[5][playerid], 255);
TextDrawFont(drawtaxi[5][playerid], 1);
TextDrawLetterSize(drawtaxi[5][playerid], 1.030000, 1.599999);
TextDrawColor(drawtaxi[5][playerid], -1);
TextDrawSetOutline(drawtaxi[5][playerid], 0);
TextDrawSetProportional(drawtaxi[5][playerid], 1);
TextDrawSetShadow(drawtaxi[5][playerid], 1);
TextDrawUseBox(drawtaxi[5][playerid], 1);
TextDrawBoxColor(drawtaxi[5][playerid], 255);
TextDrawTextSize(drawtaxi[5][playerid], 46.000000, -124.000000);

drawtaxi[6][playerid] = TextDrawCreate(373.000000, 344.000000, "_");
TextDrawAlignment(drawtaxi[6][playerid], 2);
TextDrawBackgroundColor(drawtaxi[6][playerid], 255);
TextDrawFont(drawtaxi[6][playerid], 1);
TextDrawLetterSize(drawtaxi[6][playerid], 1.030000, 1.599999);
TextDrawColor(drawtaxi[6][playerid], -1);
TextDrawSetOutline(drawtaxi[6][playerid], 0);
TextDrawSetProportional(drawtaxi[6][playerid], 1);
TextDrawSetShadow(drawtaxi[6][playerid], 1);
TextDrawUseBox(drawtaxi[6][playerid], 1);
TextDrawBoxColor(drawtaxi[6][playerid], 255);
TextDrawTextSize(drawtaxi[6][playerid], 40.000000, -64.000000);

drawtaxi[7][playerid] = TextDrawCreate(348.000000, 346.000000, "/TMENU");
TextDrawBackgroundColor(drawtaxi[7][playerid], 255);
TextDrawFont(drawtaxi[7][playerid], 2);
TextDrawLetterSize(drawtaxi[7][playerid], 0.340000, 1.100000);
TextDrawColor(drawtaxi[7][playerid], -1);
TextDrawSetOutline(drawtaxi[7][playerid], 0);
TextDrawSetProportional(drawtaxi[7][playerid], 1);
TextDrawSetShadow(drawtaxi[7][playerid], 1);

drawtaxi[8][playerid] = TextDrawCreate(434.000000, 344.000000, "_");
TextDrawAlignment(drawtaxi[8][playerid], 2);
TextDrawBackgroundColor(drawtaxi[8][playerid], 255);
TextDrawFont(drawtaxi[8][playerid], 1);
TextDrawLetterSize(drawtaxi[8][playerid], 1.030000, 1.599999);
TextDrawColor(drawtaxi[8][playerid], -1);
TextDrawSetOutline(drawtaxi[8][playerid], 0);
TextDrawSetProportional(drawtaxi[8][playerid], 1);
TextDrawSetShadow(drawtaxi[8][playerid], 1);
TextDrawUseBox(drawtaxi[8][playerid], 1);
TextDrawBoxColor(drawtaxi[8][playerid], 255);
TextDrawTextSize(drawtaxi[8][playerid], 40.000000, -62.000000);

drawtaxi[9][playerid] = TextDrawCreate(411.000000, 346.000000, "/TINFO");
TextDrawBackgroundColor(drawtaxi[9][playerid], 255);
TextDrawFont(drawtaxi[9][playerid], 2);
TextDrawLetterSize(drawtaxi[9][playerid], 0.340000, 1.100000);
TextDrawColor(drawtaxi[9][playerid], -1);
TextDrawSetOutline(drawtaxi[9][playerid], 0);
TextDrawSetProportional(drawtaxi[9][playerid], 1);
TextDrawSetShadow(drawtaxi[9][playerid], 1);

drawtaxi[10][playerid] = TextDrawCreate(312.000000, 382.000000, "_");
TextDrawAlignment(drawtaxi[10][playerid], 2);
TextDrawBackgroundColor(drawtaxi[10][playerid], 255);
TextDrawFont(drawtaxi[10][playerid], 1);
TextDrawLetterSize(drawtaxi[10][playerid], 1.030000, 3.399998);
TextDrawColor(drawtaxi[10][playerid], -1);
TextDrawSetOutline(drawtaxi[10][playerid], 0);
TextDrawSetProportional(drawtaxi[10][playerid], 1);
TextDrawSetShadow(drawtaxi[10][playerid], 1);
TextDrawUseBox(drawtaxi[10][playerid], 1);
TextDrawBoxColor(drawtaxi[10][playerid], 255);
TextDrawTextSize(drawtaxi[10][playerid], 40.000000, -62.000000);

drawtaxi[11][playerid] = TextDrawCreate(312.000000, 386.000000, "1:54");
TextDrawAlignment(drawtaxi[11][playerid], 2);
TextDrawBackgroundColor(drawtaxi[11][playerid], 255);
TextDrawFont(drawtaxi[11][playerid], 2);
TextDrawLetterSize(drawtaxi[11][playerid], 0.380000, 1.100000);
TextDrawColor(drawtaxi[11][playerid], 411893759);
TextDrawSetOutline(drawtaxi[11][playerid], 0);
TextDrawSetProportional(drawtaxi[11][playerid], 1);
TextDrawSetShadow(drawtaxi[11][playerid], 1);

drawtaxi[12][playerid] = TextDrawCreate(313.000000, 398.000000, "15000P");
TextDrawAlignment(drawtaxi[12][playerid], 2);
TextDrawBackgroundColor(drawtaxi[12][playerid], 255);
TextDrawFont(drawtaxi[12][playerid], 2);
TextDrawLetterSize(drawtaxi[12][playerid], 0.380000, 1.100000);
TextDrawColor(drawtaxi[12][playerid], 411893759);
TextDrawSetOutline(drawtaxi[12][playerid], 0);
TextDrawSetProportional(drawtaxi[12][playerid], 1);
TextDrawSetShadow(drawtaxi[12][playerid], 1);
}
if(del==1) { for(new i; i != 13; i ++) { TextDrawDestroy(drawtaxi[i][playerid]); } }
if(show==1) { for(new i; i != 10; i ++) { TextDrawShowForPlayer(playerid,drawtaxi[i][playerid]); } }
if(hide==1) { for(new i; i != 13; i ++) { TextDrawHideForPlayer(playerid,drawtaxi[i][playerid]); } }
if(dopshow==1) { for(new i=10; i != 13; i ++) { TextDrawShowForPlayer(playerid,drawtaxi[i][playerid]); } }
if(dophide==1) { for(new i=10; i != 13; i ++) { TextDrawHideForPlayer(playerid,drawtaxi[i][playerid]); } }
return 1;
}