/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM 0;
#define PD_CALL_UTILITY 1;
#define PD_CALL_BALANCES 6;
#define PD_CALL_STAKING 8;
#define PD_CALL_SESSION 9;
#define PD_CALL_DEMOCRACY 10;
#define PD_CALL_COUNCIL 11;
#define PD_CALL_TECHNICALCOMMITTEE 12;
#define PD_CALL_ELECTIONS 13;
#define PD_CALL_TREASURY 17;
#define PD_CALL_IDENTITY 24;
#define PD_CALL_RECOVERY 25;
#define PD_CALL_VESTING 26;
#define PD_CALL_SCHEDULER 27;
#define PD_CALL_PROXY 28;
#define PD_CALL_MULTISIG 29;
#define PD_CALL_XBALANCES 30;
#define PD_CALL_RBALANCES 31;
#define PD_CALL_RFIS 33;
#define PD_CALL_BRIDGESWAP 36;
#define PD_CALL_RTOKENSERIES 40;
#define PD_CALL_XCLAIM 41;
#define PD_CALL_RCLAIM 42;
#define PD_CALL_RDEXNSWAP 45;
#define PD_CALL_RDEXSWAP 46;
#define PD_CALL_LPBALANCES 47;
#define PD_CALL_RDEXMINING 48;

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V1_t payee;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_V1_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V1_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_PAYEE_V1 7
typedef struct {
    pd_RewardDestination_V1_t payee;
} pd_staking_set_payee_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 8
typedef struct {
    pd_LookupasStaticLookupSource_V1_t controller;
} pd_staking_set_controller_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 18
typedef struct {
    pd_AccountId_V1_t validator_stash;
    pd_EraIndex_V1_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_REBOND_V1 19
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V1_t;

#define PD_CALL_xbalances_transfer_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_u8_t symbol;
    pd_u128_t value;
} pd_xbalances_transfer_V1_t;

#define PD_CALL_rbalances_transfer_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_u8_t symbol;
    pd_u128_t value;
} pd_rbalances_transfer_V1_t;

#define PD_CALL_rfis_liquidity_bond_V1 18
typedef struct {
    pd_LookupasStaticLookupSource_V1_t pool;
    pd_BalanceOf_t value;
} pd_rfis_liquidity_bond_V1_t;

#define PD_CALL_rfis_liquidity_bond_and_swap_V1 19
typedef struct {
    pd_LookupasStaticLookupSource_V1_t pool;
    pd_BalanceOf_t value;
    pd_Bytes_t recipient;
    pd_u8_t dest_id;
} pd_rfis_liquidity_bond_and_swap_V1_t;

#define PD_CALL_rfis_liquidity_unbond_V1 20
typedef struct {
    pd_LookupasStaticLookupSource_V1_t pool;
    pd_u128_t value;
} pd_rfis_liquidity_unbond_V1_t;

#define PD_CALL_rfis_withdraw_unbond_V1 21
typedef struct {
    pd_LookupasStaticLookupSource_V1_t pool;
} pd_rfis_liquidity_withdraw_unbond_V1_t;

#define PD_CALL_bridgeswap_transfer_native_V1 0
typedef struct {
    pd_BalanceOf_t amount;
    pd_Bytes_t recipient;
    pd_u8_t dest_id;
} pd_bridgeswap_transfer_native_V1_t;

#define PD_CALL_bridgeswap_transfer_rtoken_V1 0
typedef struct {
    pd_u8_t symbol;
    pd_u128_t amount;
    pd_Bytes_t recipient;
    pd_u8_t dest_id;
} pd_bridgeswap_transfer_rtoken_V1_t;

#define PD_CALL_bridgeswap_transfer_xtoken_V1 0
typedef struct {
    pd_u8_t symbol;
    pd_u128_t amount;
    pd_Bytes_t recipient;
    pd_u8_t dest_id;
} pd_bridgeswap_transfer_xtoken_V1_t;

#define PD_CALL_rtokenseries_liquidity_bond_V1 13
typedef struct {
    pd_Bytes_t pubkey;
    pd_Bytes_t signature;
    pd_Bytes_t pool;
    pd_Bytes_t blockhash;
    pd_Bytes_t txhash;
    pd_u128_t amount;
    pd_u8_t symbol;
} pd_rtokenseries_liquidity_bond_V1_t;

#define PD_CALL_rtokenseries_liquidity_bond_and_swap_V1 14
typedef struct {
    pd_Bytes_t pubkey;
    pd_Bytes_t signature;
    pd_Bytes_t pool;
    pd_Bytes_t blockhash;
    pd_Bytes_t txhash;
    pd_u128_t amount;
    pd_u8_t symbol;
    pd_Bytes_t recipient;
    pd_u8_t dest_id;
} pd_rtokenseries_liquidity_bond_and_swap_V1_t;

#define PD_CALL_rtokenseries_liquidity_unbond_V1 16
typedef struct {
    pd_u8_t symbol;
    pd_Bytes_t pool;
    pd_u128_t value;
    pd_Bytes_t recipient;
} pd_rtokenseries_liquidity_unbond_V1_t;

#define PD_CALL_rtokenseries_refund_swap_fee_V1 18
typedef struct {
    pd_u8_t symbol;
    pd_Hash_t bond_id;
} pd_rtokenseries_refund_swap_fee_V1_t;

#define PD_CALL_xclaim_claim_V1 2
typedef struct {
    pd_u8_t symbol;
} pd_xclaim_claim_V1_t;

#define PD_CALL_xclaim_mint_claim_V1 3
typedef struct {
    pd_AccountId_V1_t dest;
    pd_u8_t symbol;
    pd_u128_t value;
} pd_xclaim_mint_claim_V1_t;

#define PD_CALL_rclaim_claim_rtoken_reward_V1 6
typedef struct {
    pd_u8_t symbol;
    pd_u32_t cycle;
    pd_u64_t index;
} pd_rclaim_claim_rtoken_reward_V1_t;

#define PD_CALL_rclaim_claim_reth_reward_V1 7
typedef struct {
    pd_Bytes_t pubkey;
    pd_Bytes_t sigs;
    pd_u32_t cycle;
    pd_u64_t index;
} pd_rclaim_claim_reth_reward_V1_t;

#define PD_CALL_rclaim_update_reth_claim_info_V1 8
typedef struct {
    pd_VecBytes_t pubkeys;
    pd_Vecu128_t mint_values;
    pd_Vecu128_t native_token_values;
} pd_rclaim_update_reth_claim_info_V1_t;

#define PD_CALL_rdexnswap_swap_rtoken_for_native_token_V1 0
typedef struct {
    pd_Bytes_t receiver;
    pd_u8_t symbol;
    pd_u128_t rtoken_amount;
    pd_u128_t min_out_amount;
    pd_u8_t grade;
} pd_rdexnswap_swap_rtoken_for_native_token_V1_t;

#define PD_CALL_rdexnswap_swap_rfis_for_fis_token_V1 1
typedef struct {
    pd_AccountId_V1_t receiver;
    pd_u128_t rtoken_amount;
    pd_u128_t min_out_amount;
    pd_u8_t grade;
} pd_rdexnswap_swap_rfis_for_fis_token_V1_t;

#define PD_CALL_rdexswap_swap_V1 0
typedef struct {
    pd_u8_t symbol;
    pd_u128_t input_amount;
    pd_u128_t min_out_amount;
    pd_bool_t input_is_fis;
} pd_rdexswap_swap_V1_t;

#define PD_CALL_rdexswap_add_liquidity_V1 1
typedef struct {
    pd_u8_t symbol;
    pd_u128_t rtoken_amount;
    pd_u128_t fis_amount;
} pd_rdexswap_add_liquidity_V1_t;

#define PD_CALL_rdexswap_remove_liquidity_V1 2
typedef struct {
    pd_u8_t symbol;
    pd_u128_t rm_unit;
    pd_u128_t swap_unit;
    pd_u128_t min_fis_out_amount;
    pd_u128_t min_rtoken_out_amount;
    pd_bool_t input_is_fis;
} pd_rdexswap_remove_liquidity_V1_t;

#define PD_CALL_lpbalances_transfer_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_u8_t symbol;
    pd_u128_t value;
} pd_lpbalances_transfer_V1_t;

#define PD_CALL_rdexmining_deposit_V1 0
typedef struct {
    pd_u8_t symbol;
    pd_u32_t pool_index;
    pd_u32_t grade_index;
    pd_u128_t lp_amount;
} pd_rdexmining_deposit_V1_t;

#define PD_CALL_rdexmining_withdraw_V1 1
typedef struct {
    pd_u8_t symbol;
    pd_u32_t pool_index;
    pd_u32_t stake_index;
    pd_u128_t lp_amount;
} pd_rdexmining_withdraw_V1_t;

#define PD_CALL_rdexmining_claim_reward_V1 2
typedef struct {
    pd_u8_t symbol;
    pd_u32_t pool_index;
    pd_u32_t stake_index;
} pd_rdexmining_claim_reward_V1_t;

#define PD_CALL_rdexmining_emergency_withdraw_V1 3
typedef struct {
    pd_u8_t symbol;
    pd_u32_t pool_index;
    pd_u32_t stake_index;
} pd_rdexmining_emergency_withdraw_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V1_t;

#define PD_CALL_UTILITY_AS_DERIVATIVE_V1 1
typedef struct {
    pd_u16_t index;
    pd_Call_t call;
} pd_utility_as_derivative_V1_t;

#define PD_CALL_DEMOCRACY_PROPOSE_V1 0
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactBalance_t amount;
} pd_democracy_propose_V1_t;

#define PD_CALL_DEMOCRACY_SECOND_V1 1
typedef struct {
    pd_Compactu32_t proposal;
    pd_Compactu32_t seconds_upper_bound;
} pd_democracy_second_V1_t;

#define PD_CALL_DEMOCRACY_VOTE_V1 2
typedef struct {
    pd_Compactu32_t ref_index;
    pd_AccountVote_V1_t vote;
} pd_democracy_vote_V1_t;

#define PD_CALL_DEMOCRACY_EMERGENCY_CANCEL_V1 3
typedef struct {
    pd_ReferendumIndex_V1_t ref_index;
} pd_democracy_emergency_cancel_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_MAJORITY_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_majority_V1_t;

#define PD_CALL_DEMOCRACY_EXTERNAL_PROPOSE_DEFAULT_V1 6
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_external_propose_default_V1_t;

#define PD_CALL_DEMOCRACY_FAST_TRACK_V1 7
typedef struct {
    pd_Hash_t proposal_hash;
    pd_BlockNumber_t voting_period;
    pd_BlockNumber_t delay;
} pd_democracy_fast_track_V1_t;

#define PD_CALL_DEMOCRACY_VETO_EXTERNAL_V1 8
typedef struct {
    pd_Hash_t proposal_hash;
} pd_democracy_veto_external_V1_t;

#define PD_CALL_DEMOCRACY_DELEGATE_V1 11
typedef struct {
    pd_AccountId_V1_t to;
    pd_Conviction_V1_t conviction;
    pd_Balance_t balance;
} pd_democracy_delegate_V1_t;

#define PD_CALL_DEMOCRACY_UNDELEGATE_V1 12
typedef struct {
} pd_democracy_undelegate_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_V1 14
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_PREIMAGE_OPERATIONAL_V1 15
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_V1 16
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_V1_t;

#define PD_CALL_DEMOCRACY_NOTE_IMMINENT_PREIMAGE_OPERATIONAL_V1 17
typedef struct {
    pd_Bytes_t encoded_proposal;
} pd_democracy_note_imminent_preimage_operational_V1_t;

#define PD_CALL_DEMOCRACY_REAP_PREIMAGE_V1 18
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t proposal_len_upper_bound;
} pd_democracy_reap_preimage_V1_t;

#define PD_CALL_DEMOCRACY_UNLOCK_V1 19
typedef struct {
    pd_AccountId_V1_t target;
} pd_democracy_unlock_V1_t;

#define PD_CALL_DEMOCRACY_REMOVE_VOTE_V1 20
typedef struct {
    pd_ReferendumIndex_V1_t index;
} pd_democracy_remove_vote_V1_t;

#define PD_CALL_DEMOCRACY_REMOVE_OTHER_VOTE_V1 21
typedef struct {
    pd_AccountId_V1_t target;
    pd_ReferendumIndex_V1_t index;
} pd_democracy_remove_other_vote_V1_t;

#define PD_CALL_COUNCIL_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_execute_V1_t;

#define PD_CALL_COUNCIL_PROPOSE_V1 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_council_propose_V1_t;

#define PD_CALL_COUNCIL_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_council_vote_V1_t;

#define PD_CALL_COUNCIL_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_council_close_V1_t;

#define PD_CALL_COUNCIL_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_council_disapprove_proposal_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_EXECUTE_V1 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_execute_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_PROPOSE_V1 2
typedef struct {
    pd_Compactu32_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_propose_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V1 3
typedef struct {
    pd_Hash_t proposal;
    pd_Compactu32_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE_V1 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_Compactu32_t index;
    pd_Compactu64_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_technicalcommittee_close_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_DISAPPROVE_PROPOSAL_V1 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_technicalcommittee_disapprove_proposal_V1_t;

#define PD_CALL_ELECTIONS_VOTE_V1 0
typedef struct {
    pd_VecAccountId_V1_t votes;
    pd_Compactu128_t amount;
} pd_elections_vote_V1_t;

#define PD_CALL_ELECTIONS_REMOVE_VOTER_V1 1
typedef struct {
} pd_elections_remove_voter_V1_t;

#define PD_CALL_ELECTIONS_SUBMIT_CANDIDACY_V1 2
typedef struct {
    pd_Compactu32_t candidate_count;
} pd_elections_submit_candidacy_V1_t;

#define PD_CALL_TREASURY_PROPOSE_SPEND_V1 0
typedef struct {
    pd_CompactBalance_t amount;
    pd_LookupasStaticLookupSource_V1_t beneficiary;
} pd_treasury_propose_spend_V1_t;

#define PD_CALL_TREASURY_REJECT_PROPOSAL_V1 1
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_reject_proposal_V1_t;

#define PD_CALL_TREASURY_APPROVE_PROPOSAL_V1 2
typedef struct {
    pd_Compactu32_t proposal_id;
} pd_treasury_approve_proposal_V1_t;

#define PD_CALL_TREASURY_REPORT_AWESOME_V1 3
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
} pd_treasury_report_awesome_V1_t;

#define PD_CALL_TREASURY_RETRACT_TIP_V1 4
typedef struct {
    pd_Hash_t hash;
} pd_treasury_retract_tip_V1_t;

#define PD_CALL_TREASURY_TIP_NEW_V1 5
typedef struct {
    pd_Bytes_t reason;
    pd_AccountId_V1_t who;
    pd_CompactBalance_t tip_value;
} pd_treasury_tip_new_V1_t;

#define PD_CALL_TREASURY_TIP_V1 6
typedef struct {
    pd_Hash_t hash;
    pd_CompactBalance_t tip_value;
} pd_treasury_tip_V1_t;

#define PD_CALL_TREASURY_CLOSE_TIP_V1 7
typedef struct {
    pd_Hash_t hash;
} pd_treasury_close_tip_V1_t;

#define PD_CALL_TREASURY_PROPOSE_BOUNTY_V1 8
typedef struct {
    pd_CompactBalance_t value;
    pd_Bytes_t description;
} pd_treasury_propose_bounty_V1_t;

#define PD_CALL_TREASURY_APPROVE_BOUNTY_V1 9
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_treasury_approve_bounty_V1_t;

#define PD_CALL_TREASURY_PROPOSE_CURATOR_V1 10
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V1_t curator;
    pd_CompactBalance_t fee;
} pd_treasury_propose_curator_V1_t;

#define PD_CALL_TREASURY_UNASSIGN_CURATOR_V1 11
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_treasury_unassign_curator_V1_t;

#define PD_CALL_TREASURY_ACCEPT_CURATOR_V1 12
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_treasury_accept_curator_V1_t;

#define PD_CALL_TREASURY_AWARD_BOUNTY_V1 13
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_LookupasStaticLookupSource_V1_t beneficiary;
} pd_treasury_award_bounty_V1_t;

#define PD_CALL_TREASURY_CLAIM_BOUNTY_V1 14
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_treasury_claim_bounty_V1_t;

#define PD_CALL_TREASURY_CLOSE_BOUNTY_V1 15
typedef struct {
    pd_Compactu32_t bounty_id;
} pd_treasury_close_bounty_V1_t;

#define PD_CALL_TREASURY_EXTEND_BOUNTY_EXPIRY_V1 16
typedef struct {
    pd_Compactu32_t bounty_id;
    pd_Bytes_t _remark;
} pd_treasury_extend_bounty_expiry_V1_t;

#define PD_CALL_VESTING_VEST_V1 0
typedef struct {
} pd_vesting_vest_V1_t;

#define PD_CALL_VESTING_VEST_OTHER_V1 1
typedef struct {
    pd_LookupasStaticLookupSource_V1_t target;
} pd_vesting_vest_other_V1_t;

#define PD_CALL_VESTING_VESTED_TRANSFER_V1 2
typedef struct {
    pd_LookupasStaticLookupSource_V1_t target;
    pd_VestingInfo_V1_t schedule;
} pd_vesting_vested_transfer_V1_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V1 0
typedef struct {
    pd_AccountId_V1_t account;
} pd_identity_add_registrar_V1_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V1 3
typedef struct {
} pd_identity_clear_identity_V1_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V1 4
typedef struct {
    pd_Compactu32_t reg_index;
    pd_Compactu128_t max_fee;
} pd_identity_request_judgement_V1_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V1 5
typedef struct {
    pd_RegistrarIndex_V1_t reg_index;
} pd_identity_cancel_request_V1_t;

#define PD_CALL_IDENTITY_SET_FEE_V1 6
typedef struct {
    pd_Compactu32_t index;
    pd_Compactu128_t fee;
} pd_identity_set_fee_V1_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V1 7
typedef struct {
    pd_Compactu32_t index;
    pd_AccountId_V1_t new_;
} pd_identity_set_account_id_V1_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V1 10
typedef struct {
    pd_LookupasStaticLookupSource_V1_t target;
} pd_identity_kill_identity_V1_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V1 13
typedef struct {
    pd_LookupasStaticLookupSource_V1_t sub;
} pd_identity_remove_sub_V1_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V1 14
typedef struct {
} pd_identity_quit_sub_V1_t;

#define PD_CALL_RECOVERY_AS_RECOVERED_V1 0
typedef struct {
    pd_AccountId_V1_t account;
    pd_Call_t call;
} pd_recovery_as_recovered_V1_t;

#define PD_CALL_RECOVERY_CREATE_RECOVERY_V1 2
typedef struct {
    pd_VecAccountId_V1_t friends;
    pd_u16_t threshold;
    pd_BlockNumber_t delay_period;
} pd_recovery_create_recovery_V1_t;

#define PD_CALL_RECOVERY_INITIATE_RECOVERY_V1 3
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_initiate_recovery_V1_t;

#define PD_CALL_RECOVERY_VOUCH_RECOVERY_V1 4
typedef struct {
    pd_AccountId_V1_t lost;
    pd_AccountId_V1_t rescuer;
} pd_recovery_vouch_recovery_V1_t;

#define PD_CALL_RECOVERY_CLAIM_RECOVERY_V1 5
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_claim_recovery_V1_t;

#define PD_CALL_RECOVERY_CLOSE_RECOVERY_V1 6
typedef struct {
    pd_AccountId_V1_t rescuer;
} pd_recovery_close_recovery_V1_t;

#define PD_CALL_RECOVERY_REMOVE_RECOVERY_V1 7
typedef struct {
} pd_recovery_remove_recovery_V1_t;

#define PD_CALL_RECOVERY_CANCEL_RECOVERED_V1 8
typedef struct {
    pd_AccountId_V1_t account;
} pd_recovery_cancel_recovered_V1_t;

#define pd_call_scheduler_schedule_V1 0
typedef struct {
    pd_BlockNumber_t when;
    pd_OptionschedulePeriodBlockNumber_V1_t maybe_periodic;
    pd_u8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_V1_t;

#define pd_call_scheduler_cancel_V1 0
typedef struct {
    pd_BlockNumber_t when;
    pd_u32_t index;
} pd_scheduler_cancel_V1_t;

#define pd_call_scheduler_schedule_named_V1 0
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t when;
    pd_OptionschedulePeriodBlockNumber_V1_t maybe_periodic;
    pd_u8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_V1_t;

#define pd_call_scheduler_cancel_named_V1 0
typedef struct {
    pd_Bytes_t id;
} pd_scheduler_cancel_named_V1_t;

#define pd_call_scheduler_schedule_after_V1 0
typedef struct {
    pd_BlockNumber_t after;
    pd_OptionschedulePeriodBlockNumber_V1_t maybe_periodic;
    pd_u8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_after_V1_t;

#define pd_call_scheduler_schedule_named_after_V1 0
typedef struct {
    pd_Bytes_t id;
    pd_BlockNumber_t after;
    pd_OptionschedulePeriodBlockNumber_V1_t maybe_periodic;
    pd_u8_t priority;
    pd_Call_t call;
} pd_scheduler_schedule_named_after_V1_t;

#define PD_CALL_PROXY_ADD_PROXY_V1 1
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_add_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXY_V1 2
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
} pd_proxy_remove_proxy_V1_t;

#define PD_CALL_PROXY_REMOVE_PROXIES_V1 3
typedef struct {
} pd_proxy_remove_proxies_V1_t;

#define PD_CALL_PROXY_ANONYMOUS_V1 4
typedef struct {
    pd_ProxyType_V1_t proxy_type;
    pd_BlockNumber_t delay;
    pd_u16_t index;
} pd_proxy_anonymous_V1_t;

#define PD_CALL_PROXY_KILL_ANONYMOUS_V1 5
typedef struct {
    pd_AccountId_V1_t spawner;
    pd_ProxyType_V1_t proxy_type;
    pd_u16_t index;
    pd_Compactu32_t height;
    pd_Compactu32_t ext_index;
} pd_proxy_kill_anonymous_V1_t;

#define PD_CALL_PROXY_ANNOUNCE_V1 6
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_announce_V1_t;

#define PD_CALL_PROXY_REMOVE_ANNOUNCEMENT_V1 7
typedef struct {
    pd_AccountId_V1_t real;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_remove_announcement_V1_t;

#define PD_CALL_PROXY_REJECT_ANNOUNCEMENT_V1 8
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_CallHashOf_V1_t call_hash;
} pd_proxy_reject_announcement_V1_t;

#define PD_CALL_PROXY_PROXY_ANNOUNCED_V1 9
typedef struct {
    pd_AccountId_V1_t delegate;
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_announced_V1_t;

#endif

typedef union {
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_payee_V1_t staking_set_payee_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_rfis_liquidity_bond_V1_t rfis_liquidity_bond_V1;
    pd_rfis_liquidity_bond_and_swap_V1_t rfis_liquidity_bond_and_swap_V1;
    pd_rfis_liquidity_unbond_V1_t rfis_liquidity_unbond_V1;
    pd_rfis_liquidity_withdraw_unbond_V1_t rfis_liquidity_withdraw_unbond_V1;
    pd_bridgeswap_transfer_native_V1_t bridgeswap_transfer_native_V1;
    pd_bridgeswap_transfer_rtoken_V1_t bridgeswap_transfer_rtoken_V1;
    pd_bridgeswap_transfer_xtoken_V1_t bridgeswap_transfer_xtoken_V1;
    pd_rtokenseries_liquidity_bond_V1_t rtokenseries_liquidity_bond_V1;
    pd_rtokenseries_liquidity_bond_and_swap_V1_t rtokenseries_liquidity_bond_and_swap_V1;
    pd_rtokenseries_liquidity_unbond_V1_t rtokenseries_liquidity_unbond_V1;
    pd_rtokenseries_refund_swap_fee_V1_t rtokenseries_refund_swap_fee_V1;
    pd_xclaim_claim_V1_t xclaim_claim_V1;
    pd_xclaim_mint_claim_V1_t xclaim_mint_claim_V1;
    pd_rclaim_claim_rtoken_reward_V1_t rclaim_claim_rtoken_reward_V1;
    pd_rclaim_claim_reth_reward_V1_t rclaim_claim_reth_reward_V1;
    pd_rclaim_update_reth_claim_info_V1_t rclaim_update_reth_claim_info_V1;
    pd_rdexnswap_swap_rtoken_for_native_token_V1_t rdexnswap_swap_rtoken_for_native_token_V1;
    pd_rdexnswap_swap_rfis_for_fis_token_V1_t rdexnswap_swap_rfis_for_fis_token_V1;
    pd_rdexswap_swap_V1_t rdexswap_swap_V1;
    pd_rdexswap_add_liquidity_V1_t rdexswap_add_liquidity_V1;
    pd_rdexswap_remove_liquidity_V1_t rdexswap_remove_liquidity_V1;
    pd_rdexmining_deposit_V1_t rdexmining_deposit_V1;
    pd_rdexmining_withdraw_V1_t rdexmining_withdraw_V1;
    pd_rdexmining_claim_reward_V1_t rdexmining_claim_reward_V1;
    pd_rdexmining_emergency_withdraw_V1_t rdexmining_emergency_withdraw_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_remark_V1_t system_remark_V1;
    pd_utility_as_derivative_V1_t utility_as_derivative_V1;
    pd_democracy_propose_V1_t democracy_propose_V1;
    pd_democracy_second_V1_t democracy_second_V1;
    pd_democracy_vote_V1_t democracy_vote_V1;
    pd_democracy_emergency_cancel_V1_t democracy_emergency_cancel_V1;
    pd_democracy_external_propose_V1_t democracy_external_propose_V1;
    pd_democracy_external_propose_majority_V1_t democracy_external_propose_majority_V1;
    pd_democracy_external_propose_default_V1_t democracy_external_propose_default_V1;
    pd_democracy_fast_track_V1_t democracy_fast_track_V1;
    pd_democracy_veto_external_V1_t democracy_veto_external_V1;
    pd_democracy_delegate_V1_t democracy_delegate_V1;
    pd_democracy_undelegate_V1_t democracy_undelegate_V1;
    pd_democracy_note_preimage_V1_t democracy_note_preimage_V1;
    pd_democracy_note_preimage_operational_V1_t democracy_note_preimage_operational_V1;
    pd_democracy_note_imminent_preimage_V1_t democracy_note_imminent_preimage_V1;
    pd_democracy_note_imminent_preimage_operational_V1_t democracy_note_imminent_preimage_operational_V1;
    pd_democracy_reap_preimage_V1_t democracy_reap_preimage_V1;
    pd_democracy_unlock_V1_t democracy_unlock_V1;
    pd_democracy_remove_vote_V1_t democracy_remove_vote_V1;
    pd_democracy_remove_other_vote_V1_t democracy_remove_other_vote_V1;
    pd_council_execute_V1_t council_execute_V1;
    pd_council_propose_V1_t council_propose_V1;
    pd_council_vote_V1_t council_vote_V1;
    pd_council_close_V1_t council_close_V1;
    pd_council_disapprove_proposal_V1_t council_disapprove_proposal_V1;
    pd_technicalcommittee_execute_V1_t technicalcommittee_execute_V1;
    pd_technicalcommittee_propose_V1_t technicalcommittee_propose_V1;
    pd_technicalcommittee_vote_V1_t technicalcommittee_vote_V1;
    pd_technicalcommittee_close_V1_t technicalcommittee_close_V1;
    pd_technicalcommittee_disapprove_proposal_V1_t technicalcommittee_disapprove_proposal_V1;
    pd_elections_vote_V1_t elections_vote_V1;
    pd_elections_remove_voter_V1_t elections_remove_voter_V1;
    pd_elections_submit_candidacy_V1_t elections_submit_candidacy_V1;
    pd_treasury_propose_spend_V1_t treasury_propose_spend_V1;
    pd_treasury_reject_proposal_V1_t treasury_reject_proposal_V1;
    pd_treasury_approve_proposal_V1_t treasury_approve_proposal_V1;
    pd_treasury_report_awesome_V1_t treasury_report_awesome_V1;
    pd_treasury_retract_tip_V1_t treasury_retract_tip_V1;
    pd_treasury_tip_new_V1_t treasury_tip_new_V1;
    pd_treasury_tip_V1_t treasury_tip_V1;
    pd_treasury_close_tip_V1_t treasury_close_tip_V1;
    pd_treasury_propose_bounty_V1_t treasury_propose_bounty_V1;
    pd_treasury_approve_bounty_V1_t treasury_approve_bounty_V1;
    pd_treasury_propose_curator_V1_t treasury_propose_curator_V1;
    pd_treasury_unassign_curator_V1_t treasury_unassign_curator_V1;
    pd_treasury_accept_curator_V1_t treasury_accept_curator_V1;
    pd_treasury_award_bounty_V1_t treasury_award_bounty_V1;
    pd_treasury_claim_bounty_V1_t treasury_claim_bounty_V1;
    pd_treasury_close_bounty_V1_t treasury_close_bounty_V1;
    pd_treasury_extend_bounty_expiry_V1_t treasury_extend_bounty_expiry_V1;
    pd_identity_add_registrar_V1_t identity_add_registrar_V1;
    pd_identity_clear_identity_V1_t identity_clear_identity_V1;
    pd_identity_request_judgement_V1_t identity_request_judgement_V1;
    pd_identity_cancel_request_V1_t identity_cancel_request_V1;
    pd_identity_set_fee_V1_t identity_set_fee_V1;
    pd_identity_set_account_id_V1_t identity_set_account_id_V1;
    pd_identity_kill_identity_V1_t identity_kill_identity_V1;
    pd_identity_remove_sub_V1_t identity_remove_sub_V1;
    pd_identity_quit_sub_V1_t identity_quit_sub_V1;
    pd_recovery_as_recovered_V1_t recovery_as_recovered_V1;
    pd_recovery_create_recovery_V1_t recovery_create_recovery_V1;
    pd_recovery_initiate_recovery_V1_t recovery_initiate_recovery_V1;
    pd_recovery_vouch_recovery_V1_t recovery_vouch_recovery_V1;
    pd_recovery_claim_recovery_V1_t recovery_claim_recovery_V1;
    pd_recovery_close_recovery_V1_t recovery_close_recovery_V1;
    pd_recovery_remove_recovery_V1_t recovery_remove_recovery_V1;
    pd_recovery_cancel_recovered_V1_t recovery_cancel_recovered_V1;
    pd_vesting_vest_V1_t vesting_vest_V1;
    pd_vesting_vest_other_V1_t vesting_vest_other_V1;
    pd_vesting_vested_transfer_V1_t vesting_vested_transfer_V1;
    pd_scheduler_schedule_V1_t scheduler_schedule_V1;
    pd_scheduler_cancel_V1_t scheduler_cancel_V1;
    pd_scheduler_schedule_named_V1_t scheduler_schedule_named_V1;
    pd_scheduler_cancel_named_V1_t scheduler_cancel_named_V1;
    pd_scheduler_schedule_after_V1_t scheduler_schedule_after_V1;
    pd_scheduler_schedule_named_after_V1_t scheduler_schedule_named_after_V1;
    pd_proxy_add_proxy_V1_t proxy_add_proxy_V1;
    pd_proxy_remove_proxy_V1_t proxy_remove_proxy_V1;
    pd_proxy_remove_proxies_V1_t proxy_remove_proxies_V1;
    pd_proxy_anonymous_V1_t proxy_anonymous_V1;
    pd_proxy_kill_anonymous_V1_t proxy_kill_anonymous_V1;
    pd_proxy_announce_V1_t proxy_announce_V1;
    pd_proxy_remove_announcement_V1_t proxy_remove_announcement_V1;
    pd_proxy_reject_announcement_V1_t proxy_reject_announcement_V1;
    pd_proxy_proxy_announced_V1_t proxy_proxy_announced_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V1 3
typedef struct {
    pd_LookupasStaticLookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V1_t;

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_PROXY_PROXY_V1 0
typedef struct {
    pd_AccountId_V1_t real;
    pd_OptionProxyType_V1_t force_proxy_type;
    pd_Call_t call;
} pd_proxy_proxy_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_THRESHOLD_1_V1 0
typedef struct {
    pd_VecAccountId_V1_t other_signatories;
    pd_Call_t call;
} pd_multisig_as_multi_threshold_1_V1_t;

#define PD_CALL_MULTISIG_AS_MULTI_V1 1
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_OpaqueCall_V1_t call;
    pd_bool_t store_call;
    pd_Weight_V1_t max_weight;
} pd_multisig_as_multi_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_MULTI_V1 2
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_OptionTimepoint_V1_t maybe_timepoint;
    pd_H256_t call_hash;
    pd_Weight_V1_t max_weight;
} pd_multisig_approve_as_multi_V1_t;

#define PD_CALL_MULTISIG_CANCEL_AS_MULTI_V1 3
typedef struct {
    pd_u16_t threshold;
    pd_VecAccountId_V1_t other_signatories;
    pd_Timepoint_V1_t timepoint;
    pd_H256_t call_hash;
} pd_multisig_cancel_as_multi_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_balances_transfer_keep_alive_V1_t balances_transfer_keep_alive_V1;
    pd_xbalances_transfer_V1_t xbalances_transfer_V1;
    pd_rbalances_transfer_V1_t rbalances_transfer_V1;
    pd_lpbalances_transfer_V1_t lpbalances_transfer_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_proxy_proxy_V1_t proxy_proxy_V1;
    pd_multisig_as_multi_threshold_1_V1_t multisig_as_multi_threshold_1_V1;
    pd_multisig_as_multi_V1_t multisig_as_multi_V1;
    pd_multisig_approve_as_multi_V1_t multisig_approve_as_multi_V1;
    pd_multisig_cancel_as_multi_V1_t multisig_cancel_as_multi_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
