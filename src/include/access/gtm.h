/*-------------------------------------------------------------------------
 *
 * gtm.h
 * 
 *	  Module interfacing with GTM definitions
 *
 *
 *-------------------------------------------------------------------------
 */
#ifndef ACCESS_GTM_H
#define ACCESS_GTM_H

#include "gtm/gtm_c.h"

/* Configuration variables */
extern char *GtmHost;
extern int GtmPort;
extern int GtmCoordinatorId;

extern bool IsGTMConnected(void);
extern void InitGTM(void);
extern void CloseGTM(void);
extern GlobalTransactionId BeginTranGTM(GTM_Timestamp *timestamp);
extern GlobalTransactionId BeginTranAutovacuumGTM(void);
extern int CommitTranGTM(GlobalTransactionId gxid);
extern int RollbackTranGTM(GlobalTransactionId gxid);
extern GTM_Snapshot GetSnapshotGTM(GlobalTransactionId gxid, bool canbe_grouped);

/* Sequence interface APIs with GTM */
extern GTM_Sequence GetCurrentValGTM(char *seqname);
extern GTM_Sequence GetNextValGTM(char *seqname);
extern int SetValGTM(char *seqname, GTM_Sequence nextval, bool iscalled);
extern int CreateSequenceGTM(char *seqname, GTM_Sequence increment, 
		GTM_Sequence minval, GTM_Sequence maxval, GTM_Sequence startval,
		bool cycle);
extern int AlterSequenceGTM(char *seqname, GTM_Sequence increment,
		GTM_Sequence minval, GTM_Sequence maxval, GTM_Sequence startval,
							GTM_Sequence lastval, bool cycle, bool is_restart);
extern int DropSequenceGTM(char *seqname);
extern int RenameSequenceGTM(char *seqname, const char *newseqname);
#endif /* ACCESS_GTM_H */
