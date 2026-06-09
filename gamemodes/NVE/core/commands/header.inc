#if defined _inc_header
    #undef _inc_header
#endif

#define CMD:%0(%1) forward cmd_%0(%1); public cmd_%0(%1)

#define	cmd::%0(%1) cmd_%0(%1)

#if defined OnPlayerCommandReceived
    forward OnPlayerCommandReceived(playerid, cmdtext[]);
#endif
#if defined OnPlayerCommandPerformed
    forward OnPlayerCommandPerformed(playerid, cmdtext[], success);
#endif