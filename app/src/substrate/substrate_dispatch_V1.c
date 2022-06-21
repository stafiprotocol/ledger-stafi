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

#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V1(
    parser_context_t* c, pd_balances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V1(
    parser_context_t* c, pd_balances_transfer_keep_alive_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V1(
    parser_context_t* c, pd_staking_bond_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V1(
    parser_context_t* c, pd_staking_bond_extra_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V1(
    parser_context_t* c, pd_staking_unbond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V1(
    parser_context_t* c, pd_staking_withdraw_unbonded_V1_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V1(
    parser_context_t* c, pd_staking_validate_V1_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V1(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V1(
    parser_context_t* c, pd_staking_nominate_V1_t* m)
{
    CHECK_ERROR(_readVecLookupasStaticLookupSource_V1(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V1(
    parser_context_t* c, pd_staking_chill_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V1(
    parser_context_t* c, pd_staking_set_payee_V1_t* m)
{
    CHECK_ERROR(_readRewardDestination_V1(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V1(
    parser_context_t* c, pd_staking_set_controller_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V1(
    parser_context_t* c, pd_staking_payout_stakers_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V1(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V1(
    parser_context_t* c, pd_staking_rebond_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V1(
    parser_context_t* c, pd_session_set_keys_V1_t* m)
{
    CHECK_ERROR(_readKeys_V1(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V1(
    parser_context_t* c, pd_session_purge_keys_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V1(
    parser_context_t* c, pd_utility_batch_V1_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xbalances_transfer_V1(
    parser_context_t* c, pd_xbalances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rbalances_transfer_V1(
    parser_context_t* c, pd_rbalances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rfis_liquidity_bond_V1(
    parser_context_t* c, pd_rfis_liquidity_bond_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->pool))
    CHECK_ERROR(_readBalanceOf(c, &m->value));
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rfis_liquidity_bond_and_swap_V1(
    parser_context_t* c, pd_rfis_liquidity_bond_and_swap_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->pool))
    CHECK_ERROR(_readBalanceOf(c, &m->value))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readu8(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rfis_liquidity_unbond_V1(
    parser_context_t* c, pd_rfis_liquidity_unbond_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->pool))
    CHECK_ERROR(_readu128(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rfis_liquidity_withdraw_unbond_V1(
    parser_context_t* c, pd_rfis_liquidity_withdraw_unbond_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->pool))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgeswap_transfer_native_V1(
    parser_context_t* c, pd_bridgeswap_transfer_native_V1_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readu8(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgeswap_transfer_rtoken_V1(
    parser_context_t* c, pd_bridgeswap_transfer_rtoken_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readu8(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridgeswap_transfer_xtoken_V1(
    parser_context_t* c, pd_bridgeswap_transfer_xtoken_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->amount))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readu8(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rtokenseries_liquidity_bond_V1(
    parser_context_t* c, pd_rtokenseries_liquidity_bond_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->pubkey))
    CHECK_ERROR(_readBytes(c, &m->signature))
    CHECK_ERROR(_readBytes(c, &m->pool))
    CHECK_ERROR(_readBytes(c, &m->blockhash))
    CHECK_ERROR(_readBytes(c, &m->txhash))
    CHECK_ERROR(_readu128(c, &m->amount))
    CHECK_ERROR(_readu8(c, &m->symbol))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rtokenseries_liquidity_bond_and_swap_V1(
    parser_context_t* c, pd_rtokenseries_liquidity_bond_and_swap_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->pubkey))
    CHECK_ERROR(_readBytes(c, &m->signature))
    CHECK_ERROR(_readBytes(c, &m->pool))
    CHECK_ERROR(_readBytes(c, &m->blockhash))
    CHECK_ERROR(_readBytes(c, &m->txhash))
    CHECK_ERROR(_readu128(c, &m->amount))
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    CHECK_ERROR(_readu8(c, &m->dest_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rtokenseries_liquidity_unbond_V1(
    parser_context_t* c, pd_rtokenseries_liquidity_unbond_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readBytes(c, &m->pool))
    CHECK_ERROR(_readu128(c, &m->value))
    CHECK_ERROR(_readBytes(c, &m->recipient))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rtokenseries_refund_swap_fee_V1(
    parser_context_t* c, pd_rtokenseries_refund_swap_fee_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readHash(c, &m->bond_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xclaim_claim_V1(
    parser_context_t* c, pd_xclaim_claim_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_xclaim_mint_claim_V1(
    parser_context_t* c, pd_xclaim_mint_claim_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->dest))
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rclaim_claim_rtoken_reward_V1(
    parser_context_t* c, pd_rclaim_claim_rtoken_reward_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu32(c, &m->cycle))
    CHECK_ERROR(_readu64(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rclaim_claim_reth_reward_V1(
    parser_context_t* c, pd_rclaim_claim_reth_reward_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->pubkey))
    CHECK_ERROR(_readBytes(c, &m->sigs))
    CHECK_ERROR(_readu32(c, &m->cycle))
    CHECK_ERROR(_readu64(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rclaim_update_reth_claim_info_V1(
    parser_context_t* c, pd_rclaim_update_reth_claim_info_V1_t* m)
{
    CHECK_ERROR(_readVecBytes(c, &m->pubkeys))
    CHECK_ERROR(_readVecu128(c, &m->mint_values))
    CHECK_ERROR(_readVecu128(c, &m->native_token_values))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexnswap_swap_rtoken_for_native_token_V1(
    parser_context_t* c, pd_rdexnswap_swap_rtoken_for_native_token_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->receiver))
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->rtoken_amount))
    CHECK_ERROR(_readu128(c, &m->min_out_amount))
    CHECK_ERROR(_readu8(c, &m->grade))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexnswap_swap_rfis_for_fis_token_V1(
    parser_context_t* c, pd_rdexnswap_swap_rfis_for_fis_token_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->receiver))
    CHECK_ERROR(_readu128(c, &m->rtoken_amount))
    CHECK_ERROR(_readu128(c, &m->min_out_amount))
    CHECK_ERROR(_readu8(c, &m->grade))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexswap_swap_V1(
    parser_context_t* c, pd_rdexswap_swap_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->input_amount))
    CHECK_ERROR(_readu128(c, &m->min_out_amount))
    CHECK_ERROR(_readbool(c, &m->input_is_fis))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexswap_add_liquidity_V1(
    parser_context_t* c, pd_rdexswap_add_liquidity_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->rtoken_amount))
    CHECK_ERROR(_readu128(c, &m->fis_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexswap_remove_liquidity_V1(
    parser_context_t* c, pd_rdexswap_remove_liquidity_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->rm_unit))
    CHECK_ERROR(_readu128(c, &m->swap_unit))
    CHECK_ERROR(_readu128(c, &m->min_fis_out_amount))
    CHECK_ERROR(_readu128(c, &m->min_rtoken_out_amount))
    CHECK_ERROR(_readbool(c, &m->input_is_fis))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_lpbalances_transfer_V1(
    parser_context_t* c, pd_lpbalances_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->dest))
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu128(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexmining_deposit_V1(
    parser_context_t* c, pd_rdexmining_deposit_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu32(c, &m->pool_index))
    CHECK_ERROR(_readu32(c, &m->grade_index))
    CHECK_ERROR(_readu128(c, &m->lp_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexmining_withdraw_V1(
    parser_context_t* c, pd_rdexmining_withdraw_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu32(c, &m->pool_index))
    CHECK_ERROR(_readu32(c, &m->stake_index))
    CHECK_ERROR(_readu128(c, &m->lp_amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexmining_claim_reward_V1(
    parser_context_t* c, pd_rdexmining_claim_reward_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu32(c, &m->pool_index))
    CHECK_ERROR(_readu32(c, &m->stake_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rdexmining_emergency_withdraw_V1(
    parser_context_t* c, pd_rdexmining_emergency_withdraw_V1_t* m)
{
    CHECK_ERROR(_readu8(c, &m->symbol))
    CHECK_ERROR(_readu32(c, &m->pool_index))
    CHECK_ERROR(_readu32(c, &m->stake_index))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_remark_V1(
    parser_context_t* c, pd_system_remark_V1_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_propose_V1(
    parser_context_t* c, pd_democracy_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_second_V1(
    parser_context_t* c, pd_democracy_second_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->seconds_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_vote_V1(
    parser_context_t* c, pd_democracy_vote_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->ref_index))
    CHECK_ERROR(_readAccountVote_V1(c, &m->vote))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_emergency_cancel_V1(
    parser_context_t* c, pd_democracy_emergency_cancel_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->ref_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_V1(
    parser_context_t* c, pd_democracy_external_propose_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_majority_V1(
    parser_context_t* c, pd_democracy_external_propose_majority_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_external_propose_default_V1(
    parser_context_t* c, pd_democracy_external_propose_default_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_fast_track_V1(
    parser_context_t* c, pd_democracy_fast_track_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readBlockNumber(c, &m->voting_period))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_veto_external_V1(
    parser_context_t* c, pd_democracy_veto_external_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_delegate_V1(
    parser_context_t* c, pd_democracy_delegate_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->to))
    CHECK_ERROR(_readConviction_V1(c, &m->conviction))
    CHECK_ERROR(_readBalance(c, &m->balance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_undelegate_V1(
    parser_context_t* c, pd_democracy_undelegate_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_V1(
    parser_context_t* c, pd_democracy_note_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_note_imminent_preimage_operational_V1(
    parser_context_t* c, pd_democracy_note_imminent_preimage_operational_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->encoded_proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_reap_preimage_V1(
    parser_context_t* c, pd_democracy_reap_preimage_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->proposal_len_upper_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_unlock_V1(
    parser_context_t* c, pd_democracy_unlock_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_vote_V1(
    parser_context_t* c, pd_democracy_remove_vote_V1_t* m)
{
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_democracy_remove_other_vote_V1(
    parser_context_t* c, pd_democracy_remove_other_vote_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->target))
    CHECK_ERROR(_readReferendumIndex_V1(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_execute_V1(
    parser_context_t* c, pd_council_execute_V1_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_propose_V1(
    parser_context_t* c, pd_council_propose_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_vote_V1(
    parser_context_t* c, pd_council_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_close_V1(
    parser_context_t* c, pd_council_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_council_disapprove_proposal_V1(
    parser_context_t* c, pd_council_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_execute_V1(
    parser_context_t* c, pd_technicalcommittee_execute_V1_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_propose_V1(
    parser_context_t* c, pd_technicalcommittee_propose_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V1(
    parser_context_t* c, pd_technicalcommittee_vote_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close_V1(
    parser_context_t* c, pd_technicalcommittee_close_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu64(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_disapprove_proposal_V1(
    parser_context_t* c, pd_technicalcommittee_disapprove_proposal_V1_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_vote_V1(
    parser_context_t* c, pd_elections_vote_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->votes))
    CHECK_ERROR(_readCompactu128(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_remove_voter_V1(
    parser_context_t* c, pd_elections_remove_voter_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_elections_submit_candidacy_V1(
    parser_context_t* c, pd_elections_submit_candidacy_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->candidate_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_propose_spend_V1(
    parser_context_t* c, pd_treasury_propose_spend_V1_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->beneficiary))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reject_proposal_V1(
    parser_context_t* c, pd_treasury_reject_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_approve_proposal_V1(
    parser_context_t* c, pd_treasury_approve_proposal_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_V1(
    parser_context_t* c, pd_vesting_vest_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vest_other_V1(
    parser_context_t* c, pd_vesting_vest_other_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_vesting_vested_transfer_V1(
    parser_context_t* c, pd_vesting_vested_transfer_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    CHECK_ERROR(_readVestingInfo_V1(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V1(
    parser_context_t* c, pd_identity_add_registrar_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V1(
    parser_context_t* c, pd_identity_clear_identity_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V1(
    parser_context_t* c, pd_identity_request_judgement_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->reg_index))
    CHECK_ERROR(_readCompactu128(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V1(
    parser_context_t* c, pd_identity_cancel_request_V1_t* m)
{
    CHECK_ERROR(_readRegistrarIndex_V1(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V1(
    parser_context_t* c, pd_identity_set_fee_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readCompactu128(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V1(
    parser_context_t* c, pd_identity_set_account_id_V1_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->index))
    CHECK_ERROR(_readAccountId_V1(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V1(
    parser_context_t* c, pd_identity_kill_identity_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V1(
    parser_context_t* c, pd_identity_remove_sub_V1_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource_V1(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V1(
    parser_context_t* c, pd_identity_quit_sub_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_as_recovered_V1(
    parser_context_t* c, pd_recovery_as_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_create_recovery_V1(
    parser_context_t* c, pd_recovery_create_recovery_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->friends))
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readBlockNumber(c, &m->delay_period))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_initiate_recovery_V1(
    parser_context_t* c, pd_recovery_initiate_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_vouch_recovery_V1(
    parser_context_t* c, pd_recovery_vouch_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->lost))
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_claim_recovery_V1(
    parser_context_t* c, pd_recovery_claim_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_close_recovery_V1(
    parser_context_t* c, pd_recovery_close_recovery_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->rescuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_remove_recovery_V1(
    parser_context_t* c, pd_recovery_remove_recovery_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_recovery_cancel_recovered_V1(
    parser_context_t* c, pd_recovery_cancel_recovered_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V1(
    parser_context_t* c, pd_scheduler_schedule_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionschedulePeriodBlockNumber_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readu8(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V1(
    parser_context_t* c, pd_scheduler_cancel_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V1(
    parser_context_t* c, pd_scheduler_schedule_named_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionschedulePeriodBlockNumber_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readu8(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V1(
    parser_context_t* c, pd_scheduler_cancel_named_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V1(
    parser_context_t* c, pd_scheduler_schedule_after_V1_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionschedulePeriodBlockNumber_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readu8(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V1(
    parser_context_t* c, pd_scheduler_schedule_named_after_V1_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionschedulePeriodBlockNumber_V1(c, &m->maybe_periodic))
    CHECK_ERROR(_readu8(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_V1(
    parser_context_t* c, pd_proxy_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_add_proxy_V1(
    parser_context_t* c, pd_proxy_add_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxy_V1(
    parser_context_t* c, pd_proxy_remove_proxy_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_remove_proxies_V1(
    parser_context_t* c, pd_proxy_remove_proxies_V1_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_anonymous_V1(
    parser_context_t* c, pd_proxy_anonymous_V1_t* m)
{
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readu16(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_kill_anonymous_V1(
    parser_context_t* c, pd_proxy_kill_anonymous_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->spawner))
    CHECK_ERROR(_readProxyType_V1(c, &m->proxy_type))
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCompactu32(c, &m->height))
    CHECK_ERROR(_readCompactu32(c, &m->ext_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_proxy_proxy_announced_V1(
    parser_context_t* c, pd_proxy_proxy_announced_V1_t* m)
{
    CHECK_ERROR(_readAccountId_V1(c, &m->delegate))
    CHECK_ERROR(_readAccountId_V1(c, &m->real))
    CHECK_ERROR(_readOptionProxyType_V1(c, &m->force_proxy_type))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_threshold_1_V1(
    parser_context_t* c, pd_multisig_as_multi_threshold_1_V1_t* m)
{
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_as_multi_V1(
    parser_context_t* c, pd_multisig_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readOpaqueCall_V1(c, &m->call))
    CHECK_ERROR(_readbool(c, &m->store_call))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_multi_V1(
    parser_context_t* c, pd_multisig_approve_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readOptionTimepoint_V1(c, &m->maybe_timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    CHECK_ERROR(_readWeight_V1(c, &m->max_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_cancel_as_multi_V1(
    parser_context_t* c, pd_multisig_cancel_as_multi_V1_t* m)
{
    CHECK_ERROR(_readu16(c, &m->threshold))
    CHECK_ERROR(_readVecAccountId_V1(c, &m->other_signatories))
    CHECK_ERROR(_readTimepoint_V1(c, &m->timepoint))
    CHECK_ERROR(_readH256(c, &m->call_hash))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V1(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V1_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V1(c, &method->nested.balances_transfer_V1))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V1(c, &method->nested.balances_transfer_keep_alive_V1))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V1(c, &method->basic.staking_bond_V1))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V1(c, &method->basic.staking_bond_extra_V1))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V1(c, &method->basic.staking_unbond_V1))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V1(c, &method->basic.staking_withdraw_unbonded_V1))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V1(c, &method->basic.staking_validate_V1))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V1(c, &method->basic.staking_nominate_V1))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V1(c, &method->basic.staking_chill_V1))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V1(c, &method->basic.staking_set_payee_V1))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V1(c, &method->basic.staking_set_controller_V1))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V1(c, &method->basic.staking_payout_stakers_V1))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_staking_rebond_V1(c, &method->basic.staking_rebond_V1))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V1(c, &method->basic.session_set_keys_V1))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V1(c, &method->basic.session_purge_keys_V1))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V1(c, &method->basic.utility_batch_V1))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_xbalances_transfer_V1(c, &method->basic.xbalances_transfer_V1))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_rbalances_transfer_V1(c, &method->basic.rbalances_transfer_V1))
        break;
    case 8466: /* module 33 call 18 */
        CHECK_ERROR(_readMethod_rfis_liquidity_bond_V1(c, &method->basic.rfis_liquidity_bond_V1))
        break;
    case 8467: /* module 33 call 19 */
        CHECK_ERROR(_readMethod_rfis_liquidity_bond_and_swap_V1(c, &method->basic.rfis_liquidity_bond_and_swap_V1))
        break;
    case 8468: /* module 33 call 20 */
        CHECK_ERROR(_readMethod_rfis_liquidity_unbond_V1(c, &method->basic.rfis_liquidity_unbond_V1))
        break;
    case 8469: /* module 33 call 21 */
        CHECK_ERROR(_readMethod_rfis_liquidity_withdraw_unbond_V1(c, &method->basic.rfis_liquidity_withdraw_unbond_V1))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_bridgeswap_transfer_native_V1(c, &method->basic.bridgeswap_transfer_native_V1))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_bridgeswap_transfer_rtoken_V1(c, &method->basic.bridgeswap_transfer_rtoken_V1))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_bridgeswap_transfer_xtoken_V1(c, &method->basic.bridgeswap_transfer_xtoken_V1))
        break;
    case 10253: /* module 40 call 13 */
        CHECK_ERROR(_readMethod_rtokenseries_liquidity_bond_V1(c, &method->basic.rtokenseries_liquidity_bond_V1))
        break;
    case 10254: /* module 40 call 14 */
        CHECK_ERROR(_readMethod_rtokenseries_liquidity_bond_and_swap_V1(c, &method->basic.rtokenseries_liquidity_bond_and_swap_V1))
        break;
    case 10256: /* module 40 call 16 */
        CHECK_ERROR(_readMethod_rtokenseries_liquidity_unbond_V1(c, &method->basic.rtokenseries_liquidity_unbond_V1))
        break;
    case 10258: /* module 40 call 18 */
        CHECK_ERROR(_readMethod_rtokenseries_refund_swap_fee_V1(c, &method->basic.rtokenseries_refund_swap_fee_V1))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_xclaim_claim_V1(c, &method->basic.xclaim_claim_V1))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_xclaim_mint_claim_V1(c, &method->basic.xclaim_mint_claim_V1))
        break;
    case 10759: /* module 42 call 6 */
        CHECK_ERROR(_readMethod_rclaim_claim_rtoken_reward_V1(c, &method->basic.rclaim_claim_rtoken_reward_V1))
        break;
    case 10760: /* module 42 call 7 */
        CHECK_ERROR(_readMethod_rclaim_claim_reth_reward_V1(c, &method->basic.rclaim_claim_reth_reward_V1))
        break;
    case 10761: /* module 42 call 8 */
        CHECK_ERROR(_readMethod_rclaim_update_reth_claim_info_V1(c, &method->basic.rclaim_update_reth_claim_info_V1))
        break;
    case 11520: /* module 45 call 0 */
        CHECK_ERROR(_readMethod_rdexnswap_swap_rtoken_for_native_token_V1(c, &method->basic.rdexnswap_swap_rtoken_for_native_token_V1))
        break;
    case 11521: /* module 45 call 1 */
        CHECK_ERROR(_readMethod_rdexnswap_swap_rfis_for_fis_token_V1(c, &method->basic.rdexnswap_swap_rfis_for_fis_token_V1))
        break;
    case 11776: /* module 46 call 0 */
        CHECK_ERROR(_readMethod_rdexswap_swap_V1(c, &method->basic.rdexswap_swap_V1))
        break;
    case 11777: /* module 46 call 1 */
        CHECK_ERROR(_readMethod_rdexswap_add_liquidity_V1(c, &method->basic.rdexswap_add_liquidity_V1))
        break;
    case 11778: /* module 46 call 2 */
        CHECK_ERROR(_readMethod_rdexswap_remove_liquidity_V1(c, &method->basic.rdexswap_remove_liquidity_V1))
        break;
    case 12032: /* module 47 call 0 */
        CHECK_ERROR(_readMethod_lpbalances_transfer_V1(c, &method->basic.lpbalances_transfer_V1))
        break;
    case 12288: /* module 48 call 0 */
        CHECK_ERROR(_readMethod_rdexmining_deposit_V1(c, &method->basic.rdexmining_deposit_V1))
        break;
    case 12289: /* module 48 call 1 */
        CHECK_ERROR(_readMethod_rdexmining_withdraw_V1(c, &method->basic.rdexmining_withdraw_V1))
        break;
    case 12290: /* module 48 call 2 */
        CHECK_ERROR(_readMethod_rdexmining_claim_reward_V1(c, &method->basic.rdexmining_claim_reward_V1))
        break;
    case 12291: /* module 48 call 3 */
        CHECK_ERROR(_readMethod_rdexmining_emergency_withdraw_V1(c, &method->basic.rdexmining_emergency_withdraw_V1))
        break;
#ifdef SUBSTRATE_PARSER_FULL
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V1(c, &method->nested.system_remark_V1))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_democracy_propose_V1(c, &method->basic.democracy_propose_V1))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_democracy_second_V1(c, &method->basic.democracy_second_V1))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_democracy_vote_V1(c, &method->basic.democracy_vote_V1))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_democracy_emergency_cancel_V1(c, &method->basic.democracy_emergency_cancel_V1))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_democracy_external_propose_V1(c, &method->basic.democracy_external_propose_V1))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_democracy_external_propose_majority_V1(c, &method->basic.democracy_external_propose_majority_V1))
        break;
    case 2566: /* module 10 call 6 */
        CHECK_ERROR(_readMethod_democracy_external_propose_default_V1(c, &method->basic.democracy_external_propose_default_V1))
        break;
    case 2567: /* module 10 call 7 */
        CHECK_ERROR(_readMethod_democracy_fast_track_V1(c, &method->basic.democracy_fast_track_V1))
        break;
    case 2568: /* module 10 call 8 */
        CHECK_ERROR(_readMethod_democracy_veto_external_V1(c, &method->basic.democracy_veto_external_V1))
        break;
    case 2571: /* module 10 call 11 */
        CHECK_ERROR(_readMethod_democracy_delegate_V1(c, &method->basic.democracy_delegate_V1))
        break;
    case 2572: /* module 10 call 12 */
        CHECK_ERROR(_readMethod_democracy_undelegate_V1(c, &method->basic.democracy_undelegate_V1))
        break;
    case 2574: /* module 10 call 14 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_V1(c, &method->basic.democracy_note_preimage_V1))
        break;
    case 2575: /* module 10 call 15 */
        CHECK_ERROR(_readMethod_democracy_note_preimage_operational_V1(c, &method->basic.democracy_note_preimage_operational_V1))
        break;
    case 2576: /* module 10 call 16 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_V1(c, &method->basic.democracy_note_imminent_preimage_V1))
        break;
    case 2577: /* module 10 call 17 */
        CHECK_ERROR(_readMethod_democracy_note_imminent_preimage_operational_V1(c, &method->basic.democracy_note_imminent_preimage_operational_V1))
        break;
    case 2578: /* module 10 call 18 */
        CHECK_ERROR(_readMethod_democracy_reap_preimage_V1(c, &method->basic.democracy_reap_preimage_V1))
        break;
    case 2579: /* module 10 call 19 */
        CHECK_ERROR(_readMethod_democracy_unlock_V1(c, &method->basic.democracy_unlock_V1))
        break;
    case 2580: /* module 10 call 20 */
        CHECK_ERROR(_readMethod_democracy_remove_vote_V1(c, &method->basic.democracy_remove_vote_V1))
        break;
    case 2581: /* module 10 call 21 */
        CHECK_ERROR(_readMethod_democracy_remove_other_vote_V1(c, &method->basic.democracy_remove_other_vote_V1))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_council_execute_V1(c, &method->basic.council_execute_V1))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_council_propose_V1(c, &method->basic.council_propose_V1))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_council_vote_V1(c, &method->basic.council_vote_V1))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_council_close_V1(c, &method->basic.council_close_V1))
        break;
    case 2821: /* module 11 call 5 */
        CHECK_ERROR(_readMethod_council_disapprove_proposal_V1(c, &method->basic.council_disapprove_proposal_V1))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_execute_V1(c, &method->basic.technicalcommittee_execute_V1))
        break;
    case 3074: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_propose_V1(c, &method->basic.technicalcommittee_propose_V1))
        break;
    case 3075: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V1(c, &method->basic.technicalcommittee_vote_V1))
        break;
    case 3076: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_close_V1(c, &method->basic.technicalcommittee_close_V1))
        break;
    case 3077: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_technicalcommittee_disapprove_proposal_V1(c, &method->basic.technicalcommittee_disapprove_proposal_V1))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_elections_vote_V1(c, &method->basic.elections_vote_V1))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_elections_remove_voter_V1(c, &method->basic.elections_remove_voter_V1))
        break;
    case 3331: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_elections_submit_candidacy_V1(c, &method->basic.elections_submit_candidacy_V1))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_treasury_propose_spend_V1(c, &method->basic.treasury_propose_spend_V1))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_treasury_reject_proposal_V1(c, &method->basic.treasury_reject_proposal_V1))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_treasury_approve_proposal_V1(c, &method->basic.treasury_approve_proposal_V1))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_identity_add_registrar_V1(c, &method->basic.identity_add_registrar_V1))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_identity_clear_identity_V1(c, &method->basic.identity_clear_identity_V1))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_identity_request_judgement_V1(c, &method->basic.identity_request_judgement_V1))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_identity_cancel_request_V1(c, &method->basic.identity_cancel_request_V1))
        break;
    case 6150: /* module 24 call 6 */
        CHECK_ERROR(_readMethod_identity_set_fee_V1(c, &method->basic.identity_set_fee_V1))
        break;
    case 6151: /* module 24 call 7 */
        CHECK_ERROR(_readMethod_identity_set_account_id_V1(c, &method->basic.identity_set_account_id_V1))
        break;
    case 6154: /* module 24 call 10 */
        CHECK_ERROR(_readMethod_identity_kill_identity_V1(c, &method->basic.identity_kill_identity_V1))
        break;
    case 6157: /* module 24 call 13 */
        CHECK_ERROR(_readMethod_identity_remove_sub_V1(c, &method->basic.identity_remove_sub_V1))
        break;
    case 6158: /* module 24 call 14 */
        CHECK_ERROR(_readMethod_identity_quit_sub_V1(c, &method->basic.identity_quit_sub_V1))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_recovery_as_recovered_V1(c, &method->basic.recovery_as_recovered_V1))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_recovery_create_recovery_V1(c, &method->basic.recovery_create_recovery_V1))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_recovery_initiate_recovery_V1(c, &method->basic.recovery_initiate_recovery_V1))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_recovery_vouch_recovery_V1(c, &method->basic.recovery_vouch_recovery_V1))
        break;
    case 6405: /* module 25 call 5 */
        CHECK_ERROR(_readMethod_recovery_claim_recovery_V1(c, &method->basic.recovery_claim_recovery_V1))
        break;
    case 6406: /* module 25 call 6 */
        CHECK_ERROR(_readMethod_recovery_close_recovery_V1(c, &method->basic.recovery_close_recovery_V1))
        break;
    case 6407: /* module 25 call 7 */
        CHECK_ERROR(_readMethod_recovery_remove_recovery_V1(c, &method->basic.recovery_remove_recovery_V1))
        break;
    case 6408: /* module 25 call 8 */
        CHECK_ERROR(_readMethod_recovery_cancel_recovered_V1(c, &method->basic.recovery_cancel_recovered_V1))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_vesting_vest_V1(c, &method->basic.vesting_vest_V1))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_vesting_vest_other_V1(c, &method->basic.vesting_vest_other_V1))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_vesting_vested_transfer_V1(c, &method->basic.vesting_vested_transfer_V1))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V1(c, &method->basic.scheduler_schedule_V1))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V1(c, &method->basic.scheduler_cancel_V1))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V1(c, &method->basic.scheduler_schedule_named_V1))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V1(c, &method->basic.scheduler_cancel_named_V1))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V1(c, &method->basic.scheduler_schedule_after_V1))
        break;
    case 6917: /* module 27 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V1(c, &method->basic.scheduler_schedule_named_after_V1))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_proxy_proxy_V1(c, &method->nested.proxy_proxy_V1))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_proxy_add_proxy_V1(c, &method->basic.proxy_add_proxy_V1))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_proxy_remove_proxy_V1(c, &method->basic.proxy_remove_proxy_V1))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_proxy_remove_proxies_V1(c, &method->basic.proxy_remove_proxies_V1))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_proxy_anonymous_V1(c, &method->basic.proxy_anonymous_V1))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_proxy_kill_anonymous_V1(c, &method->basic.proxy_kill_anonymous_V1))
        break;
    case 7177: /* module 28 call 9 */
        CHECK_ERROR(_readMethod_proxy_proxy_announced_V1(c, &method->basic.proxy_proxy_announced_V1))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_multisig_as_multi_threshold_1_V1(c, &method->nested.multisig_as_multi_threshold_1_V1))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_multisig_as_multi_V1(c, &method->nested.multisig_as_multi_V1))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_multisig_approve_as_multi_V1(c, &method->nested.multisig_approve_as_multi_V1))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_multisig_cancel_as_multi_V1(c, &method->nested.multisig_cancel_as_multi_V1))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V1(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 1:
        return STR_MO_UTILITY;
    case 6:
        return STR_MO_BALANCES;
    case 8:
        return STR_MO_STAKING;
    case 9:
        return STR_MO_SESSION;
    case 30:
        return STR_MO_XBALANCES;
    case 31:
        return STR_MO_RBALANCES;
    case 33:
        return STR_MO_RFIS;
    case 36:
        return STR_MO_BRIDGESWAP;
    case 40:
        return STR_MO_RTOKENSERIES;
    case 41:
        return STR_MO_XCLAIM;
    case 42:
        return STR_MO_RCLAIM;
    case 45:
        return STR_MO_RDEXNSWAP;
    case 46:
        return STR_MO_RDEXSWAP;
    case 47:
        return STR_MO_LPBALANCES;
    case 48:
        return STR_MO_RDEXMINING;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 10:
        return STR_MO_DEMOCRACY;
    case 11:
        return STR_MO_COUNCIL;
    case 12:
        return STR_MO_TECHNICALCOMMITTEE;
    case 13:
        return STR_MO_ELECTIONS;
    case 17:
        return STR_MO_TREASURY;
    case 24:
        return STR_MO_IDENTITY;
    case 25:
        return STR_MO_RECOVERY;
    case 26:
        return STR_MO_VESTING;
    case 27:
        return STR_MO_SCHEDULER;
    case 28:
        return STR_MO_PROXY;
    case 29:
        return STR_MO_MULTISIG;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return STR_ME_TRANSFER;
    case 1539: /* module 6 call 3 */
        return STR_ME_TRANSFER_KEEP_ALIVE;
    case 2048: /* module 8 call 0 */
        return STR_ME_BOND;
    case 2049: /* module 8 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2050: /* module 8 call 2 */
        return STR_ME_UNBOND;
    case 2051: /* module 8 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2052: /* module 8 call 4 */
        return STR_ME_VALIDATE;
    case 2053: /* module 8 call 5 */
        return STR_ME_NOMINATE;
    case 2054: /* module 8 call 6 */
        return STR_ME_CHILL;
    case 2055: /* module 8 call 7 */
        return STR_ME_SET_PAYEE;
    case 2056: /* module 8 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2066: /* module 8 call 18 */
        return STR_ME_PAYOUT_STAKERS;
    case 2067: /* module 8 call 19 */
        return STR_ME_REBOND;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_KEYS;
    case 2305: /* module 9 call 1 */
        return STR_ME_PURGE_KEYS;
    case 256: /* module 1 call 0 */
        return STR_ME_BATCH;
    case 7680: /* module 30 call 0 */
        return STR_ME_TRANSFER;
    case 7936: /* module 31 call 0 */
        return STR_ME_TRANSFER;
    case 8466: /* module 33 call 18 */
        return STR_ME_LIQUIDITY_BOND;
    case 8467: /* module 33 call 19 */
        return STR_ME_LIQUIDITY_BOND_AND_SWAP;
    case 8468: /* module 33 call 20 */
        return STR_ME_LIQUIDITY_UNBOND;
    case 8469: /* module 33 call 21 */
        return STR_ME_LIQUIDITY_WITHDRAW_UNBOND;
    case 9216: /* module 36 call 0 */
        return STR_ME_TRANSFER_NATIVE;
    case 9218: /* module 36 call 2 */
        return STR_ME_TRANSFER_RTOKEN;
    case 9220: /* module 36 call 4 */
        return STR_ME_TRANSFER_XTOKEN;
    case 10253: /* module 40 call 13 */
        return STR_ME_LIQUIDITY_BOND;
    case 10254: /* module 40 call 14 */
        return STR_ME_LIQUIDITY_BOND_AND_SWAP;
    case 10256: /* module 40 call 16 */
        return STR_ME_LIQUIDITY_UNBOND;
    case 10258: /* module 40 call 18 */
        return STR_ME_REFUND_SWAP_FEE;
    case 10498: /* module 41 call 2 */
        return STR_ME_CLAIM;
    case 10499: /* module 41 call 3 */
        return STR_ME_MINT_CLAIM;
    case 10759: /* module 42 call 6 */
        return STR_ME_CLAIM_RTOKEN_REWARD;
    case 10760: /* module 42 call 7 */
        return STR_ME_CLAIM_RETH_REWARD;
    case 10761: /* module 42 call 8 */
        return STR_ME_UPDATE_RETH_CLAIM_INFO;
    case 11520: /* module 45 call 0 */
        return STR_ME_SWAP_RTOKEN_FOR_NATIVE_TOKEN;
    case 11521: /* module 45 call 1 */
        return STR_ME_SWAP_RFIS_FOR_FIS_TOKEN;
    case 11776: /* module 46 call 0 */
        return STR_ME_SWAP;
    case 11777: /* module 46 call 1 */
        return STR_ME_ADD_LIQUIDITY;
    case 11778: /* module 46 call 2 */
        return STR_ME_REMOVE_LIQUIDITY;
    case 12032: /* module 47 call 0 */
        return STR_ME_TRANSFER;
    case 12288: /* module 48 call 0 */
        return STR_ME_DEPOSIT;
    case 12289: /* module 48 call 1 */
        return STR_ME_WITHDRAW;
    case 12290: /* module 48 call 2 */
        return STR_ME_CLAIM_REWARD;
    case 12291: /* module 48 call 3 */
        return STR_ME_EMERGENCY_WITHDRAW;
    default:
        return _getMethod_Name_V1_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V1_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2560: /* module 10 call 0 */
        return STR_ME_PROPOSE;
    case 2561: /* module 10 call 1 */
        return STR_ME_SECOND;
    case 2562: /* module 10 call 2 */
        return STR_ME_VOTE;
    case 2563: /* module 10 call 3 */
        return STR_ME_EMERGENCY_CANCEL;
    case 2564: /* module 10 call 4 */
        return STR_ME_EXTERNAL_PROPOSE;
    case 2565: /* module 10 call 5 */
        return STR_ME_EXTERNAL_PROPOSE_MAJORITY;
    case 2566: /* module 10 call 6 */
        return STR_ME_EXTERNAL_PROPOSE_DEFAULT;
    case 2567: /* module 10 call 7 */
        return STR_ME_FAST_TRACK;
    case 2568: /* module 10 call 8 */
        return STR_ME_VETO_EXTERNAL;
    case 2571: /* module 10 call 11 */
        return STR_ME_DELEGATE;
    case 2572: /* module 10 call 12 */
        return STR_ME_UNDELEGATE;
    case 2574: /* module 10 call 14 */
        return STR_ME_NOTE_PREIMAGE;
    case 2575: /* module 10 call 15 */
        return STR_ME_NOTE_PREIMAGE_OPERATIONAL;
    case 2576: /* module 10 call 16 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE;
    case 2577: /* module 10 call 17 */
        return STR_ME_NOTE_IMMINENT_PREIMAGE_OPERATIONAL;
    case 2578: /* module 10 call 18 */
        return STR_ME_REAP_PREIMAGE;
    case 2579: /* module 10 call 19 */
        return STR_ME_UNLOCK;
    case 2580: /* module 10 call 20 */
        return STR_ME_REMOVE_VOTE;
    case 2581: /* module 10 call 21 */
        return STR_ME_REMOVE_OTHER_VOTE;
    case 2817: /* module 11 call 1 */
        return STR_ME_EXECUTE;
    case 2818: /* module 11 call 2 */
        return STR_ME_PROPOSE;
    case 2819: /* module 11 call 3 */
        return STR_ME_VOTE;
    case 2820: /* module 11 call 4 */
        return STR_ME_CLOSE;
    case 2821: /* module 11 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3073: /* module 12 call 1 */
        return STR_ME_EXECUTE;
    case 3074: /* module 16 call 2 */
        return STR_ME_PROPOSE;
    case 3075: /* module 16 call 3 */
        return STR_ME_VOTE;
    case 3076: /* module 16 call 4 */
        return STR_ME_CLOSE;
    case 3077: /* module 16 call 5 */
        return STR_ME_DISAPPROVE_PROPOSAL;
    case 3328: /* module 13 call 0 */
        return STR_ME_VOTE;
    case 3329: /* module 13 call 1 */
        return STR_ME_REMOVE_VOTER;
    case 3331: /* module 13 call 2 */
        return STR_ME_SUBMIT_CANDIDACY;
    case 4352: /* module 17 call 0 */
        return STR_ME_PROPOSE_SPEND;
    case 4353: /* module 17 call 1 */
        return STR_ME_REJECT_PROPOSAL;
    case 4354: /* module 17 call 2 */
        return STR_ME_APPROVE_PROPOSAL;
    case 6144: /* module 24 call 0 */
        return STR_ME_ADD_REGISTRAR;
    case 6147: /* module 24 call 3 */
        return STR_ME_CLEAR_IDENTITY;
    case 6148: /* module 24 call 4 */
        return STR_ME_REQUEST_JUDGEMENT;
    case 6149: /* module 24 call 5 */
        return STR_ME_CANCEL_REQUEST;
    case 6150: /* module 24 call 6 */
        return STR_ME_SET_FEE;
    case 6151: /* module 24 call 7 */
        return STR_ME_SET_ACCOUNT_ID;
    case 6154: /* module 24 call 10 */
        return STR_ME_KILL_IDENTITY;
    case 6157: /* module 24 call 13 */
        return STR_ME_REMOVE_SUB;
    case 6158: /* module 24 call 14 */
        return STR_ME_QUIT_SUB;
    case 6400: /* module 25 call 0 */
        return STR_ME_AS_RECOVERED;
    case 6402: /* module 25 call 2 */
        return STR_ME_CREATE_RECOVERY;
    case 6403: /* module 25 call 3 */
        return STR_ME_INITIATE_RECOVERY;
    case 6404: /* module 25 call 4 */
        return STR_ME_VOUCH_RECOVERY;
    case 6405: /* module 25 call 5 */
        return STR_ME_CLAIM_RECOVERY;
    case 6406: /* module 25 call 6 */
        return STR_ME_CLOSE_RECOVERY;
    case 6407: /* module 25 call 7 */
        return STR_ME_REMOVE_RECOVERY;
    case 6408: /* module 25 call 8 */
        return STR_ME_CANCEL_RECOVERED;
    case 6656: /* module 26 call 0 */
        return STR_ME_VEST;
    case 6657: /* module 26 call 1 */
        return STR_ME_VEST_OTHER;
    case 6658: /* module 26 call 2 */
        return STR_ME_VESTED_TRANSFER;
    case 6912: /* module 27 call 0 */
        return STR_ME_SCHEDULE;
    case 6913: /* module 27 call 1 */
        return STR_ME_CANCEL;
    case 6914: /* module 27 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 6915: /* module 27 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 6916: /* module 27 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 6917: /* module 27 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 7168: /* module 28 call 0 */
        return STR_ME_PROXY;
    case 7169: /* module 28 call 1 */
        return STR_ME_ADD_PROXY;
    case 7170: /* module 28 call 2 */
        return STR_ME_REMOVE_PROXY;
    case 7171: /* module 28 call 3 */
        return STR_ME_REMOVE_PROXIES;
    case 7172: /* module 28 call 4 */
        return STR_ME_ANONYMOUS;
    case 7173: /* module 28 call 5 */
        return STR_ME_KILL_ANONYMOUS;
    case 7177: /* module 28 call 9 */
        return STR_ME_PROXY_ANNOUNCED;
    case 7424: /* module 29 call 0 */
        return STR_ME_AS_MULTI_THRESHOLD_1;
    case 7425: /* module 29 call 1 */
        return STR_ME_AS_MULTI;
    case 7426: /* module 29 call 2 */
        return STR_ME_APPROVE_AS_MULTI;
    case 7427: /* module 29 call 3 */
        return STR_ME_CANCEL_AS_MULTI;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        return 2;
    case 1539: /* module 6 call 3 */
        return 2;
    case 2048: /* module 8 call 0 */
        return 3;
    case 2049: /* module 8 call 1 */
        return 1;
    case 2050: /* module 8 call 2 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 0;
    case 2055: /* module 8 call 7 */
        return 1;
    case 2056: /* module 8 call 8 */
        return 1;
    case 2066: /* module 8 call 18 */
        return 2;
    case 2067: /* module 8 call 19 */
        return 1;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 0;
    case 256: /* module 1 call 0 */
        return 1;
    case 7680: /* module 30 call 0 */
        return 3;
    case 7936: /* module 31 call 0 */
        return 3;
    case 8466: /* module 33 call 18 */
        return 2;
    case 8467: /* module 33 call 19 */
        return 4;
    case 8468: /* module 33 call 20 */
        return 2;
    case 8469: /* module 33 call 21 */
        return 1;
    case 9216: /* module 36 call 0 */
        return 3;
    case 9218: /* module 36 call 2 */
        return 4;
    case 9220: /* module 36 call 4 */
        return 4;
    case 10253: /* module 40 call 13 */
        return 7;
    case 10254: /* module 40 call 14 */
        return 9;
    case 10256: /* module 40 call 16 */
        return 4;
    case 10258: /* module 40 call 18 */
        return 2;
    case 10498: /* module 41 call 2 */
        return 1;
    case 10499: /* module 41 call 3 */
        return 3;
    case 10759: /* module 42 call 6 */
        return 3;
    case 10760: /* module 42 call 7 */
        return 4;
    case 10761: /* module 42 call 8 */
        return 3;
    case 11520: /* module 45 call 0 */
        return 5;
    case 11521: /* module 45 call 1 */
        return 4;
    case 11776: /* module 46 call 0 */
        return 4;
    case 11777: /* module 46 call 1 */
        return 3;
    case 11778: /* module 46 call 2 */
        return 6;
    case 12032: /* module 47 call 0 */
        return 3;
    case 12288: /* module 48 call 0 */
        return 4;
    case 12289: /* module 48 call 1 */
        return 4;
    case 12290: /* module 48 call 2 */
        return 3;
    case 12291: /* module 48 call 3 */
        return 3;
#ifdef SUBSTRATE_PARSER_FULL
    case 1: /* module 0 call 1 */
        return 1;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 2;
    case 2562: /* module 10 call 2 */
        return 2;
    case 2563: /* module 10 call 3 */
        return 1;
    case 2564: /* module 10 call 4 */
        return 1;
    case 2565: /* module 10 call 5 */
        return 1;
    case 2566: /* module 10 call 6 */
        return 1;
    case 2567: /* module 10 call 7 */
        return 3;
    case 2568: /* module 10 call 8 */
        return 1;
    case 2571: /* module 10 call 11 */
        return 3;
    case 2572: /* module 10 call 12 */
        return 0;
    case 2574: /* module 10 call 14 */
        return 1;
    case 2575: /* module 10 call 15 */
        return 1;
    case 2576: /* module 10 call 16 */
        return 1;
    case 2577: /* module 10 call 17 */
        return 1;
    case 2578: /* module 10 call 18 */
        return 2;
    case 2579: /* module 10 call 19 */
        return 1;
    case 2580: /* module 10 call 20 */
        return 1;
    case 2581: /* module 10 call 21 */
        return 2;
    case 2817: /* module 11 call 1 */
        return 2;
    case 2818: /* module 11 call 2 */
        return 3;
    case 2819: /* module 11 call 3 */
        return 3;
    case 2820: /* module 11 call 4 */
        return 4;
    case 2821: /* module 11 call 5 */
        return 1;
    case 3073: /* module 12 call 1 */
        return 2;
    case 3328: /* module 13 call 0 */
        return 2;
    case 3329: /* module 13 call 1 */
        return 0;
    case 3331: /* module 13 call 2 */
        return 1;
    case 3074: /* module 16 call 2 */
        return 3;
    case 3075: /* module 16 call 3 */
        return 3;
    case 3076: /* module 16 call 4 */
        return 4;
    case 3077: /* module 16 call 5 */
        return 1;
    case 4352: /* module 17 call 0 */
        return 2;
    case 4353: /* module 17 call 1 */
        return 1;
    case 4354: /* module 17 call 2 */
        return 1;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6147: /* module 24 call 3 */
        return 0;
    case 6148: /* module 24 call 4 */
        return 2;
    case 6149: /* module 24 call 5 */
        return 1;
    case 6150: /* module 24 call 6 */
        return 2;
    case 6151: /* module 24 call 7 */
        return 2;
    case 6154: /* module 24 call 10 */
        return 1;
    case 6157: /* module 24 call 13 */
        return 1;
    case 6158: /* module 24 call 14 */
        return 0;
    case 6400: /* module 25 call 0 */
        return 2;
    case 6402: /* module 25 call 2 */
        return 3;
    case 6403: /* module 25 call 3 */
        return 1;
    case 6404: /* module 25 call 4 */
        return 2;
    case 6405: /* module 25 call 5 */
        return 1;
    case 6406: /* module 25 call 6 */
        return 1;
    case 6407: /* module 25 call 7 */
        return 0;
    case 6408: /* module 25 call 8 */
        return 1;
    case 6656: /* module 26 call 0 */
        return 0;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 2;
    case 6912: /* module 27 call 0 */
        return 4;
    case 6913: /* module 27 call 1 */
        return 2;
    case 6914: /* module 27 call 2 */
        return 5;
    case 6915: /* module 27 call 3 */
        return 1;
    case 6916: /* module 27 call 4 */
        return 4;
    case 6917: /* module 27 call 5 */
        return 5;
    case 7168: /* module 28 call 0 */
        return 3;
    case 7169: /* module 28 call 1 */
        return 3;
    case 7170: /* module 28 call 2 */
        return 3;
    case 7171: /* module 28 call 3 */
        return 0;
    case 7172: /* module 28 call 4 */
        return 3;
    case 7173: /* module 28 call 5 */
        return 5;
    case 7177: /* module 28 call 9 */
        return 4;
    case 7424: /* module 29 call 0 */
        return 2;
    case 7425: /* module 29 call 1 */
        return 6;
    case 7426: /* module 29 call 2 */
        return 5;
    case 7427: /* module 29 call 3 */
        return 4;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_symbol;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_symbol;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8466: /* module 33 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8467: /* module 33 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_recipient;
        case 3:
            return STR_IT_dest_id;
        default:
            return NULL;
        }
    case 8468: /* module 33 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 8469: /* module 33 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pool;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_recipient;
        case 2:
            return STR_IT_dest_id;
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_recipient;
        case 3:
            return STR_IT_dest_id;
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_recipient;
        case 3:
            return STR_IT_dest_id;
        default:
            return NULL;
        }
    case 10253: /* module 40 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pubkey;
        case 1:
            return STR_IT_signature;
        case 2:
            return STR_IT_pool;
        case 3:
            return STR_IT_blockhash;
        case 4:
            return STR_IT_txhash;
        case 5:
            return STR_IT_amount;
        case 6:
            return STR_IT_symbol;
        default:
            return NULL;
        }
    case 10254: /* module 40 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pubkey;
        case 1:
            return STR_IT_signature;
        case 2:
            return STR_IT_pool;
        case 3:
            return STR_IT_blockhash;
        case 4:
            return STR_IT_txhash;
        case 5:
            return STR_IT_amount;
        case 6:
            return STR_IT_symbol;
        case 7:
            return STR_IT_recipient;
        case 8:
            return STR_IT_dest_id;
        default:
            return NULL;
        }
    case 10256: /* module 40 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_pool;
        case 2:
            return STR_IT_value;
        case 3:
            return STR_IT_recipient;
        default:
            return NULL;
        }
    case 10258: /* module 40 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_bond_id;
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_symbol;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 10759: /* module 42 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_cycle;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 10760: /* module 42 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pubkey;
        case 1:
            return STR_IT_sigs;
        case 2:
            return STR_IT_cycle;
        case 3:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 10761: /* module 42 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pubkeys;
        case 1:
            return STR_IT_mint_values;
        case 2:
            return STR_IT_native_token_values;
        default:
            return NULL;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_receiver;
        case 1:
            return STR_IT_symbol;
        case 2:
            return STR_IT_rtoken_amount;
        case 3:
            return STR_IT_min_out_amount;
        case 4:
            return STR_IT_grade;
        default:
            return NULL;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_receiver;
        case 1:
            return STR_IT_rtoken_amount;
        case 2:
            return STR_IT_min_out_amount;
        case 3:
            return STR_IT_grade;
        default:
            return NULL;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_input_amount;
        case 2:
            return STR_IT_min_out_amount;
        case 3:
            return STR_IT_input_is_fis;
        default:
            return NULL;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_rtoken_amount;
        case 2:
            return STR_IT_fis_amount;
        default:
            return NULL;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_rm_unit;
        case 2:
            return STR_IT_swap_unit;
        case 3:
            return STR_IT_min_fis_out_amount;
        case 4:
            return STR_IT_min_rtoken_out_amount;
        case 5:
            return STR_IT_input_is_fis;
        default:
            return NULL;
        }
    case 12032: /* module 47 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_symbol;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 12288: /* module 48 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_pool_index;
        case 2:
            return STR_IT_grade_index;
        case 3:
            return STR_IT_lp_amount;
        default:
            return NULL;
        }
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_pool_index;
        case 2:
            return STR_IT_stake_index;
        case 3:
            return STR_IT_lp_amount;
        default:
            return NULL;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_pool_index;
        case 2:
            return STR_IT_stake_index;
        default:
            return NULL;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_symbol;
        case 1:
            return STR_IT_pool_index;
        case 2:
            return STR_IT_stake_index;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_seconds_upper_bound;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        case 1:
            return STR_IT_vote;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ref_index;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2567: /* module 10 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_voting_period;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 2571: /* module 10 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_to;
        case 1:
            return STR_IT_conviction;
        case 2:
            return STR_IT_balance;
        default:
            return NULL;
        }
    case 2572: /* module 10 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2574: /* module 10 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2575: /* module 10 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2576: /* module 10 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2577: /* module 10 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_encoded_proposal;
        default:
            return NULL;
        }
    case 2578: /* module 10 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_proposal_len_upper_bound;
        default:
            return NULL;
        }
    case 2579: /* module 10 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 2580: /* module 10 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2581: /* module 10 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3074: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3075: /* module 16 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3076: /* module 16 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_proposal_weight_bound;
        case 3:
            return STR_IT_length_bound;
        default:
            return NULL;
        }
    case 3077: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_hash;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_votes;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3331: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_candidate_count;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_beneficiary;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        case 1:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reg_index;
        default:
            return NULL;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_fee;
        default:
            return NULL;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_new;
        default:
            return NULL;
        }
    case 6154: /* module 24 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6157: /* module 24 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sub;
        default:
            return NULL;
        }
    case 6158: /* module 24 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_friends;
        case 1:
            return STR_IT_threshold;
        case 2:
            return STR_IT_delay_period;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_lost;
        case 1:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rescuer;
        default:
            return NULL;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6408: /* module 25 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_account;
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_when;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_after;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_after;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_real;
        case 1:
            return STR_IT_force_proxy_type;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_delay;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proxy_type;
        case 1:
            return STR_IT_delay;
        case 2:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_spawner;
        case 1:
            return STR_IT_proxy_type;
        case 2:
            return STR_IT_index;
        case 3:
            return STR_IT_height;
        case 4:
            return STR_IT_ext_index;
        default:
            return NULL;
        }
    case 7177: /* module 28 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delegate;
        case 1:
            return STR_IT_real;
        case 2:
            return STR_IT_force_proxy_type;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_other_signatories;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call;
        case 4:
            return STR_IT_store_call;
        case 5:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_maybe_timepoint;
        case 3:
            return STR_IT_call_hash;
        case 4:
            return STR_IT_max_weight;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_threshold;
        case 1:
            return STR_IT_other_signatories;
        case 2:
            return STR_IT_timepoint;
        case 3:
            return STR_IT_call_hash;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V1(
    pd_Method_V1_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_transfer_keep_alive_V1 - dest */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->nested.balances_transfer_keep_alive_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_keep_alive_V1 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_keep_alive_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_bond_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_bond_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_bond_extra_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_unbond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V1 - num_slashing_spans */;
            return _toStringu32(
                &m->basic.staking_withdraw_unbonded_V1.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V1 - prefs */;
            return _toStringValidatorPrefs_V1(
                &m->basic.staking_validate_V1.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V1 - targets */;
            return _toStringVecLookupasStaticLookupSource_V1(
                &m->basic.staking_nominate_V1.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V1 - payee */;
            return _toStringRewardDestination_V1(
                &m->basic.staking_set_payee_V1.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V1 - controller */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.staking_set_controller_V1.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V1 - validator_stash */;
            return _toStringAccountId_V1(
                &m->basic.staking_payout_stakers_V1.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V1 - era */;
            return _toStringEraIndex_V1(
                &m->basic.staking_payout_stakers_V1.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.staking_rebond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V1 - keys */;
            return _toStringKeys_V1(
                &m->basic.session_set_keys_V1.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V1 - proof */;
            return _toStringBytes(
                &m->basic.session_set_keys_V1.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V1 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_V1.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.xbalances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringu8(
                &m->basic.xbalances_transfer_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2:
            return _toStringu128(
                &m->basic.xbalances_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.rbalances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringu8(
                &m->basic.rbalances_transfer_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2:
            return _toStringu128(
                &m->basic.rbalances_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 8466: /* module 33 call 18 */
        switch (itemIdx) {
        case 0:
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.rfis_liquidity_bond_V1.pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringBalanceOf(
                &m->basic.rfis_liquidity_bond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 8467: /* module 33 call 19 */
        switch (itemIdx) {
        case 0:
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.rfis_liquidity_bond_and_swap_V1.pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringBalanceOf(
                &m->basic.rfis_liquidity_bond_and_swap_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2:
            return _toStringBytes(
                &m->basic.rfis_liquidity_bond_and_swap_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3:
            return _toStringu8(
                &m->basic.rfis_liquidity_bond_and_swap_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 8468: /* module 33 call 20 */
        switch (itemIdx) {
        case 0:
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.rfis_liquidity_unbond_V1.pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringu128(
                &m->basic.rfis_liquidity_unbond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 8469: /* module 33 call 21 */
         switch (itemIdx) {
         case 0:
             return _toStringLookupasStaticLookupSource_V1(
                 &m->basic.rfis_liquidity_withdraw_unbond_V1.pool,
                 outValue, outValueLen,
                 pageIdx, pageCount);
         default:
             return NULL;
         }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return _toStringBalanceOf(
                &m->basic.bridgeswap_transfer_native_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringBytes(
                &m->basic.bridgeswap_transfer_native_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2:
            return _toStringu8(
                &m->basic.bridgeswap_transfer_native_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0:
            return _toStringu8(
                &m->basic.bridgeswap_transfer_rtoken_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringu128(
                &m->basic.bridgeswap_transfer_rtoken_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2:
            return _toStringBytes(
                &m->basic.bridgeswap_transfer_rtoken_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3:
            return _toStringu8(
                &m->basic.bridgeswap_transfer_rtoken_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return _toStringu8(
                &m->basic.bridgeswap_transfer_xtoken_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1:
            return _toStringu128(
                &m->basic.bridgeswap_transfer_xtoken_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2:
            return _toStringBytes(
                &m->basic.bridgeswap_transfer_xtoken_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3:
            return _toStringu8(
                &m->basic.bridgeswap_transfer_xtoken_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10253: /* module 40 call 13 */
        switch (itemIdx) {
        case 0: /* rtokenseries_liquidity_bond_V1 - pubkey */
            return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_V1.pubkey,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rtokenseries_liquidity_bond_V1 - signature */
            return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_V1.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rtokenseries_liquidity_bond_V1 - pool */
           return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_V1.pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rtokenseries_liquidity_bond_V1 - blockhash */
           return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_V1.blockhash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* rtokenseries_liquidity_bond_V1 - txhash */
           return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_V1.txhash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* rtokenseries_liquidity_bond_V1 - amount */
           return _toStringu128(
                &m->basic.rtokenseries_liquidity_bond_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* rtokenseries_liquidity_bond_V1 - symbol */
           return _toStringu8(
                &m->basic.rtokenseries_liquidity_bond_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10254: /* module 40 call 14 */
        switch (itemIdx) {
        case 0: /* rtokenseries_liquidity_bond_and_swap_V1 - pubkey */
            return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.pubkey,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rtokenseries_liquidity_bond_and_swap_V1 - signature */
            return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rtokenseries_liquidity_bond_and_swap_V1 - pool */
           return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rtokenseries_liquidity_bond_and_swap_V1 - blockhash */
           return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.blockhash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* rtokenseries_liquidity_bond_and_swap_V1 - txhash */
           return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.txhash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* rtokenseries_liquidity_bond_and_swap_V1 - amount */
           return _toStringu128(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* rtokenseries_liquidity_bond_and_swap_V1 - symbol */
           return _toStringu8(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* rtokenseries_liquidity_bond_and_swap_V1 - recipient */
            return _toStringBytes(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 8: /* rtokenseries_liquidity_bond_and_swap_V1 - dest_id */
            return _toStringu8(
                &m->basic.rtokenseries_liquidity_bond_and_swap_V1.dest_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10256: /* module 40 call 16 */
        switch (itemIdx) {
        case 0: /* rtokenseries_liquidity_unbond_V1 - symbol */
           return _toStringu8(
                &m->basic.rtokenseries_liquidity_unbond_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rtokenseries_liquidity_unbond_V1 - pool */
           return _toStringBytes(
                &m->basic.rtokenseries_liquidity_unbond_V1.pool,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rtokenseries_liquidity_unbond_V1 - value */
           return _toStringu128(
                &m->basic.rtokenseries_liquidity_unbond_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rtokenseries_liquidity_unbond_V1 - recipient */
            return _toStringBytes(
                &m->basic.rtokenseries_liquidity_unbond_V1.recipient,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10258: /* module 40 call 18 */
        switch (itemIdx) {
        case 0: /* rtokenseries_refund_swap_fee_V1 - symbol */
           return _toStringu8(
                &m->basic.rtokenseries_refund_swap_fee_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rtokenseries_refund_swap_fee_V1 - bond_id */
           return _toStringHash(
                &m->basic.rtokenseries_refund_swap_fee_V1.bond_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* xclaim_claim_V1 - recipient */
           return _toStringu8(
                &m->basic.xclaim_claim_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* xclaim_mint_claim_V1 - dest */
            return _toStringAccountId_V1(
                &m->basic.xclaim_mint_claim_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* xclaim_mint_claim_V1 - symbol */
            return _toStringu8(
                &m->basic.xclaim_mint_claim_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* xclaim_mint_claim_V1 - value */
            return _toStringu128(
                &m->basic.xclaim_mint_claim_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10759: /* module 42 call 6 for seiya*/
        switch (itemIdx) {
        case 0: /* rclaim_claim_rtoken_reward_V1 - symbol */
            return _toStringu8(
                &m->basic.rclaim_claim_rtoken_reward_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rclaim_claim_rtoken_reward_V1 - cycle */
            return _toStringu32(
                &m->basic.rclaim_claim_rtoken_reward_V1.cycle,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rclaim_claim_rtoken_reward_V1 - index */
            return _toStringu64(
                &m->basic.rclaim_claim_rtoken_reward_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10760: /* module 42 call 7 */
        switch (itemIdx) {
        case 0: /* rclaim_claim_reth_reward_V1 - pubkey */
            return _toStringBytes(
                &m->basic.rclaim_claim_reth_reward_V1.pubkey,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rclaim_claim_reth_reward_V1 - sigs */
            return _toStringBytes(
                &m->basic.rclaim_claim_reth_reward_V1.sigs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rclaim_claim_reth_reward_V1 - cycle */
            return _toStringu32(
                &m->basic.rclaim_claim_reth_reward_V1.cycle,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rclaim_claim_reth_reward_V1 - index */
            return _toStringu64(
                &m->basic.rclaim_claim_reth_reward_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 10761: /* module 42 call 8 */
        switch (itemIdx) {
        case 0: /* rclaim_update_reth_claim_info_V1 - pubkeys */
            return _toStringVecBytes(
                &m->basic.rclaim_update_reth_claim_info_V1.pubkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rclaim_update_reth_claim_info_V1 - mint_values */
            return _toStringVecu128(
                &m->basic.rclaim_update_reth_claim_info_V1.mint_values,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rclaim_update_reth_claim_info_V1 - native_token_values */
            return _toStringVecu128(
                &m->basic.rclaim_update_reth_claim_info_V1.native_token_values,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0: /* rdexnswap_swap_rtoken_for_native_token_V1 - receiver */
            return _toStringBytes(
                &m->basic.rdexnswap_swap_rtoken_for_native_token_V1.receiver,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexnswap_swap_rtoken_for_native_token_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexnswap_swap_rtoken_for_native_token_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexnswap_swap_rtoken_for_native_token_V1 - rtoken_amount */
            return _toStringu128(
                &m->basic.rdexnswap_swap_rtoken_for_native_token_V1.rtoken_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rdexnswap_swap_rtoken_for_native_token_V1 - min_out_amount */
            return _toStringu128(
                &m->basic.rdexnswap_swap_rtoken_for_native_token_V1.min_out_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* rdexnswap_swap_rtoken_for_native_token_V1 - grade */
            return _toStringu8(
                &m->basic.rdexnswap_swap_rtoken_for_native_token_V1.grade,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0: /* rdexnswap_swap_rfis_for_fis_token_V1 - receiver */
            return _toStringAccountId_V1(
                &m->basic.rdexnswap_swap_rfis_for_fis_token_V1.receiver,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexnswap_swap_rfis_for_fis_token_V1 - rtoken_amount */
            return _toStringu128(
                &m->basic.rdexnswap_swap_rfis_for_fis_token_V1.rtoken_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexnswap_swap_rfis_for_fis_token_V1 - min_out_amount */
            return _toStringu128(
                &m->basic.rdexnswap_swap_rfis_for_fis_token_V1.min_out_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rdexnswap_swap_rfis_for_fis_token_V1 - grade */
            return _toStringu8(
                &m->basic.rdexnswap_swap_rfis_for_fis_token_V1.grade,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0: /* rdexswap_swap_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexswap_swap_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexswap_swap_V1 - input_amount */
            return _toStringu128(
                &m->basic.rdexswap_swap_V1.input_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexswap_swap_V1 - min_out_amount */
            return _toStringu128(
                &m->basic.rdexswap_swap_V1.min_out_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rdexswap_swap_V1 - input_is_fis */
            return _toStringbool(
                &m->basic.rdexswap_swap_V1.input_is_fis,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0: /* rdexswap_add_liquidity_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexswap_add_liquidity_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexswap_add_liquidity_V1 - rtoken_amount */
            return _toStringu128(
                &m->basic.rdexswap_add_liquidity_V1.rtoken_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexswap_add_liquidity_V1 - fis_amount */
            return _toStringu128(
                &m->basic.rdexswap_add_liquidity_V1.fis_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0: /* rdexswap_remove_liquidity_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexswap_remove_liquidity_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexswap_remove_liquidity_V1 - rm_unit */
            return _toStringu128(
                &m->basic.rdexswap_remove_liquidity_V1.rm_unit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexswap_remove_liquidity_V1 - swap_unit */
            return _toStringu128(
                &m->basic.rdexswap_remove_liquidity_V1.swap_unit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rdexswap_remove_liquidity_V1 - min_fis_out_amount */
            return _toStringu128(
                &m->basic.rdexswap_remove_liquidity_V1.min_fis_out_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* rdexswap_remove_liquidity_V1 - min_rtoken_out_amount */
            return _toStringu128(
                &m->basic.rdexswap_remove_liquidity_V1.min_rtoken_out_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* rdexswap_remove_liquidity_V1 - input_is_fis */
            return _toStringbool(
                &m->basic.rdexswap_remove_liquidity_V1.input_is_fis,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 12032: /* module 47 call 0 */
        switch (itemIdx) {
        case 0: /* lpbalances_transfer_V1 - dest */
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.lpbalances_transfer_V1.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* lpbalances_transfer_V1 - symbol */
            return _toStringu8(
                &m->basic.lpbalances_transfer_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* lpbalances_transfer_V1 - value */
            return _toStringu128(
                &m->basic.lpbalances_transfer_V1.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 12288: /* module 48 call 0 */
        switch (itemIdx) {
        case 0: /* rdexmining_deposit_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexmining_deposit_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexmining_deposit_V1 - pool_index */
            return _toStringu32(
                &m->basic.rdexmining_deposit_V1.pool_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexmining_deposit_V1 - grade_index */
            return _toStringu32(
                &m->basic.rdexmining_deposit_V1.grade_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rdexmining_deposit_V1 - lp_amount */
            return _toStringu128(
                &m->basic.rdexmining_deposit_V1.lp_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0: /* rdexmining_withdraw_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexmining_withdraw_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexmining_withdraw_V1 - pool_index */
            return _toStringu32(
                &m->basic.rdexmining_withdraw_V1.pool_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexmining_withdraw_V1 - stake_index */
            return _toStringu32(
                &m->basic.rdexmining_withdraw_V1.stake_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* rdexmining_withdraw_V1 - lp_amount */
            return _toStringu128(
                &m->basic.rdexmining_withdraw_V1.lp_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0: /* rdexmining_claim_reward_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexmining_claim_reward_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexmining_claim_reward_V1 - pool_index */
            return _toStringu32(
                &m->basic.rdexmining_claim_reward_V1.pool_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexmining_claim_reward_V1 - stake_index */
            return _toStringu32(
                &m->basic.rdexmining_claim_reward_V1.stake_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0: /* rdexmining_emergency_withdraw_V1 - symbol */
            return _toStringu8(
                &m->basic.rdexmining_emergency_withdraw_V1.symbol,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rdexmining_emergency_withdraw_V1 - pool_index */
            return _toStringu32(
                &m->basic.rdexmining_emergency_withdraw_V1.pool_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rdexmining_emergency_withdraw_V1 - stake_index */
            return _toStringu32(
                &m->basic.rdexmining_emergency_withdraw_V1.stake_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V1 - remark */;
            return _toStringVecu8(
                &m->nested.system_remark_V1.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* democracy_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_propose_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.democracy_propose_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* democracy_second_V1 - proposal */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_second_V1 - seconds_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_second_V1.seconds_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* democracy_vote_V1 - ref_index */;
            return _toStringCompactu32(
                &m->basic.democracy_vote_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_vote_V1 - vote */;
            return _toStringAccountVote_V1(
                &m->basic.democracy_vote_V1.vote,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* democracy_emergency_cancel_V1 - ref_index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_emergency_cancel_V1.ref_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_majority_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_majority_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        case 0: /* democracy_external_propose_default_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_external_propose_default_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2567: /* module 10 call 7 */
        switch (itemIdx) {
        case 0: /* democracy_fast_track_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_fast_track_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_fast_track_V1 - voting_period */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V1.voting_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_fast_track_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.democracy_fast_track_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2568: /* module 10 call 8 */
        switch (itemIdx) {
        case 0: /* democracy_veto_external_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_veto_external_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2571: /* module 10 call 11 */
        switch (itemIdx) {
        case 0: /* democracy_delegate_V1 - to */;
            return _toStringAccountId_V1(
                &m->basic.democracy_delegate_V1.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_delegate_V1 - conviction */;
            return _toStringConviction_V1(
                &m->basic.democracy_delegate_V1.conviction,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* democracy_delegate_V1 - balance */;
            return _toStringBalance(
                &m->basic.democracy_delegate_V1.balance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2572: /* module 10 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2574: /* module 10 call 14 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2575: /* module 10 call 15 */
        switch (itemIdx) {
        case 0: /* democracy_note_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2576: /* module 10 call 16 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2577: /* module 10 call 17 */
        switch (itemIdx) {
        case 0: /* democracy_note_imminent_preimage_operational_V1 - encoded_proposal */;
            return _toStringBytes(
                &m->basic.democracy_note_imminent_preimage_operational_V1.encoded_proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2578: /* module 10 call 18 */
        switch (itemIdx) {
        case 0: /* democracy_reap_preimage_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.democracy_reap_preimage_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_reap_preimage_V1 - proposal_len_upper_bound */;
            return _toStringCompactu32(
                &m->basic.democracy_reap_preimage_V1.proposal_len_upper_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2579: /* module 10 call 19 */
        switch (itemIdx) {
        case 0: /* democracy_unlock_V1 - target */;
            return _toStringAccountId_V1(
                &m->basic.democracy_unlock_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2580: /* module 10 call 20 */
        switch (itemIdx) {
        case 0: /* democracy_remove_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_remove_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2581: /* module 10 call 21 */
        switch (itemIdx) {
        case 0: /* democracy_remove_other_vote_V1 - target */;
            return _toStringAccountId_V1(
                &m->basic.democracy_remove_other_vote_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* democracy_remove_other_vote_V1 - index */;
            return _toStringReferendumIndex_V1(
                &m->basic.democracy_remove_other_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* council_execute_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_execute_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_execute_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_execute_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* council_propose_V1 - threshold */;
            return _toStringCompactu32(
                &m->basic.council_propose_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_propose_V1 - proposal */;
            return _toStringProposal(
                &m->basic.council_propose_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_propose_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_propose_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* council_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.council_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_vote_V1 - index */;
            return _toStringCompactu32(
                &m->basic.council_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.council_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* council_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* council_close_V1 - index */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* council_close_V1 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.council_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* council_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.council_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2821: /* module 11 call 5 */
        switch (itemIdx) {
        case 0: /* council_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.council_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_execute_V1 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_execute_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_execute_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_execute_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_propose_V1 - threshold */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_propose_V1 - proposal */;
            return _toStringProposal(
                &m->basic.technicalcommittee_propose_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_propose_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_propose_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 16 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V1 - proposal */;
            return _toStringHash(
                &m->basic.technicalcommittee_vote_V1.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V1 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_vote_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V1 - approve */;
            return _toStringbool(
                &m->basic.technicalcommittee_vote_V1.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 16 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_close_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_close_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_close_V1 - index */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_close_V1 - proposal_weight_bound */;
            return _toStringCompactu64(
                &m->basic.technicalcommittee_close_V1.proposal_weight_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* technicalcommittee_close_V1 - length_bound */;
            return _toStringCompactu32(
                &m->basic.technicalcommittee_close_V1.length_bound,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3077: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_disapprove_proposal_V1 - proposal_hash */;
            return _toStringHash(
                &m->basic.technicalcommittee_disapprove_proposal_V1.proposal_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* elections_vote_V1 - votes */;
            return _toStringVecAccountId_V1(
                &m->basic.elections_vote_V1.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* elections_vote_V1 - amount */;
            return _toStringCompactu128(
                &m->basic.elections_vote_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* elections_submit_candidacy_V1 - candidate_count */;
            return _toStringCompactu32(
                &m->basic.elections_submit_candidacy_V1.candidate_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_propose_spend_V1 - amount */;
            return _toStringCompactBalance(
                &m->basic.treasury_propose_spend_V1.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* treasury_propose_spend_V1 - beneficiary */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.treasury_propose_spend_V1.beneficiary,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reject_proposal_V1 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_reject_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* treasury_approve_proposal_V1 - proposal_id */;
            return _toStringCompactu32(
                &m->basic.treasury_approve_proposal_V1.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* identity_add_registrar_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.identity_add_registrar_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* identity_request_judgement_V1 - reg_index */;
            return _toStringCompactu32(
                &m->basic.identity_request_judgement_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_request_judgement_V1 - max_fee */;
            return _toStringCompactu128(
                &m->basic.identity_request_judgement_V1.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0: /* identity_cancel_request_V1 - reg_index */;
            return _toStringRegistrarIndex_V1(
                &m->basic.identity_cancel_request_V1.reg_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0: /* identity_set_fee_V1 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_fee_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_fee_V1 - fee */;
            return _toStringCompactu128(
                &m->basic.identity_set_fee_V1.fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        case 0: /* identity_set_account_id_V1 - index */;
            return _toStringCompactu32(
                &m->basic.identity_set_account_id_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_account_id_V1 - new_ */;
            return _toStringAccountId_V1(
                &m->basic.identity_set_account_id_V1.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6154: /* module 24 call 10 */
        switch (itemIdx) {
        case 0: /* identity_kill_identity_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_kill_identity_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6157: /* module 24 call 13 */
        switch (itemIdx) {
        case 0: /* identity_remove_sub_V1 - sub */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.identity_remove_sub_V1.sub,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6158: /* module 24 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* recovery_as_recovered_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_as_recovered_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_as_recovered_V1 - call */;
            return _toStringCall(
                &m->basic.recovery_as_recovered_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* recovery_create_recovery_V1 - friends */;
            return _toStringVecAccountId_V1(
                &m->basic.recovery_create_recovery_V1.friends,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_create_recovery_V1 - threshold */;
            return _toStringu16(
                &m->basic.recovery_create_recovery_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* recovery_create_recovery_V1 - delay_period */;
            return _toStringBlockNumber(
                &m->basic.recovery_create_recovery_V1.delay_period,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* recovery_initiate_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_initiate_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* recovery_vouch_recovery_V1 - lost */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.lost,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* recovery_vouch_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_vouch_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 6405: /* module 25 call 5 */
        switch (itemIdx) {
        case 0: /* recovery_claim_recovery_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_claim_recovery_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 6406: /* module 25 call 6 */
        switch (itemIdx) {
        case 0: /* recovery_close_recovery_V1 - rescuer */;
            return _toStringAccountId_V1(
                &m->basic.recovery_close_recovery_V1.rescuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 6407: /* module 25 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6408: /* module 25 call 8 */
        switch (itemIdx) {
        case 0: /* recovery_cancel_recovered_V1 - account */;
            return _toStringAccountId_V1(
                &m->basic.recovery_cancel_recovered_V1.account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* vesting_vest_other_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.vesting_vest_other_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* vesting_vested_transfer_V1 - target */;
            return _toStringLookupasStaticLookupSource_V1(
                &m->basic.vesting_vested_transfer_V1.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* vesting_vested_transfer_V1 - schedule */;
            return _toStringVestingInfo_V1(
                &m->basic.vesting_vested_transfer_V1.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V1 - maybe_periodic */;
            return _toStringOptionschedulePeriodBlockNumber_V1(
                &m->basic.scheduler_schedule_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V1 - priority */;
            return _toStringu8(
                &m->basic.scheduler_schedule_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_cancel_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V1 - index */;
            return _toStringu32(
                &m->basic.scheduler_cancel_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V1 - when */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_V1.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V1 - maybe_periodic */;
            return _toStringOptionschedulePeriodBlockNumber_V1(
                &m->basic.scheduler_schedule_named_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V1 - priority */;
            return _toStringu8(
                &m->basic.scheduler_schedule_named_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
         switch (itemIdx) {
         case 0: /* scheduler_cancel_named_V1 - id */;
             return _toStringBytes(
                 &m->basic.scheduler_cancel_named_V1.id,
                 outValue, outValueLen,
                 pageIdx, pageCount);
         default:
             return parser_no_data;
         }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V1 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_after_V1.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V1 - maybe_periodic */;
            return _toStringOptionschedulePeriodBlockNumber_V1(
                &m->basic.scheduler_schedule_after_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V1 - priority */;
            return _toStringu8(
                &m->basic.scheduler_schedule_after_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_after_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6917: /* module 27 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V1 - id */;
            return _toStringBytes(
                &m->basic.scheduler_schedule_named_after_V1.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V1 - after */;
            return _toStringBlockNumber(
                &m->basic.scheduler_schedule_named_after_V1.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V1 - maybe_periodic */;
            return _toStringOptionschedulePeriodBlockNumber_V1(
                &m->basic.scheduler_schedule_named_after_V1.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V1 - priority */;
            return _toStringu8(
                &m->basic.scheduler_schedule_named_after_V1.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V1 - call */;
            return _toStringCall(
                &m->basic.scheduler_schedule_named_after_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_V1 - real */;
            return _toStringAccountId_V1(
                &m->nested.proxy_proxy_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->nested.proxy_proxy_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_V1 - call */;
            return _toStringCall(
                &m->nested.proxy_proxy_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* proxy_add_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_add_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_add_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_add_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_add_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_add_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* proxy_remove_proxy_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_remove_proxy_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_remove_proxy_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_remove_proxy_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_remove_proxy_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_remove_proxy_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* proxy_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_anonymous_V1 - delay */;
            return _toStringBlockNumber(
                &m->basic.proxy_anonymous_V1.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* proxy_kill_anonymous_V1 - spawner */;
            return _toStringAccountId_V1(
                &m->basic.proxy_kill_anonymous_V1.spawner,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_kill_anonymous_V1 - proxy_type */;
            return _toStringProxyType_V1(
                &m->basic.proxy_kill_anonymous_V1.proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_kill_anonymous_V1 - index */;
            return _toStringu16(
                &m->basic.proxy_kill_anonymous_V1.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_kill_anonymous_V1 - height */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.height,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* proxy_kill_anonymous_V1 - ext_index */;
            return _toStringCompactu32(
                &m->basic.proxy_kill_anonymous_V1.ext_index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7177: /* module 28 call 9 */
        switch (itemIdx) {
        case 0: /* proxy_proxy_announced_V1 - delegate */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.delegate,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* proxy_proxy_announced_V1 - real */;
            return _toStringAccountId_V1(
                &m->basic.proxy_proxy_announced_V1.real,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* proxy_proxy_announced_V1 - force_proxy_type */;
            return _toStringOptionProxyType_V1(
                &m->basic.proxy_proxy_announced_V1.force_proxy_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* proxy_proxy_announced_V1 - call */;
            return _toStringCall(
                &m->basic.proxy_proxy_announced_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_threshold_1_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_as_multi_threshold_1_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_threshold_1_V1 - call */;
            return _toStringCall(
                &m->nested.multisig_as_multi_threshold_1_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_as_multi_V1 - call */;
            return _toStringOpaqueCall_V1(
                &m->nested.multisig_as_multi_V1.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_as_multi_V1 - store_call */;
            return _toStringbool(
                &m->nested.multisig_as_multi_V1.store_call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* multisig_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_approve_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_approve_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_approve_as_multi_V1 - maybe_timepoint */;
            return _toStringOptionTimepoint_V1(
                &m->nested.multisig_approve_as_multi_V1.maybe_timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_approve_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_approve_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* multisig_approve_as_multi_V1 - max_weight */;
            return _toStringWeight_V1(
                &m->nested.multisig_approve_as_multi_V1.max_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_cancel_as_multi_V1 - threshold */;
            return _toStringu16(
                &m->nested.multisig_cancel_as_multi_V1.threshold,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_cancel_as_multi_V1 - other_signatories */;
            return _toStringVecAccountId_V1(
                &m->nested.multisig_cancel_as_multi_V1.other_signatories,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_cancel_as_multi_V1 - timepoint */;
            return _toStringTimepoint_V1(
                &m->nested.multisig_cancel_as_multi_V1.timepoint,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_cancel_as_multi_V1 - call_hash */;
            return _toStringH256(
                &m->nested.multisig_cancel_as_multi_V1.call_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V1(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2051: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2063: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2069: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V1(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
//    case 768: // Timestamp:Set
//    case 1024: // Indices:Claim
//    case 1026: // Indices:Free
//    case 1027: // Indices:Force transfer
//    case 1028: // Indices:Freeze
    case 2048: // Staking:Bond
    case 2049: // Staking:Bond extra
    case 2050: // Staking:Unbond
    case 2051: // Staking:Withdraw Unbonded
    case 2052: // Staking:Validate
    case 2053: // Staking:Nominate
    case 2054: // Staking:Chill
    case 2055: // Staking:Set payee
    case 2056: // Staking:Set controller
    case 2057: // Staking:Set validator count
    case 2058: // Staking:Increase validator count
    case 2060: // Staking:Force no eras
    case 2061: // Staking:Force new era
    case 2063: // Staking:Force unstake
    case 2064: // Staking:Force new era always
    case 2066: // Staking:Payout stakers
    case 2067: // Staking:Rebond
    case 2068: // Staking:Set history depth
    case 2069: // Staking:Reap stash
//    case 1816: // Staking:Chill other
    case 2304: // Session:Set keys
    case 2305: // Session:Purge keys
    case 7680:  /* XBalances: transfer */
    case 7936: /* RBalances: transfer */
    case 8466: /* RFis: liquidity bond */
    case 8467: /* RFis: liquidity bond and swap */
    case 8468: /* RFis: liquidity unbond */
    case 8469: /* RFis: liquidity withdraw unbond */
    case 9216: /* BridgeSwap: transfer native */
    case 9218: /* BridgeSwap: transfer rtoken */
    case 9220: /* BridgeSwap: transfer xtoken */
    case 10253: /* module 40 call 13 */
    case 10254: /* module 40 call 14 */
    case 10256: /* module 40 call 16 */
    case 10258: /* module 40 call 18 */
    case 10498: /* module 41 call 2 */
    case 10499: /* module 41 call 3 */
    case 10759: /* module 42 call 6 */
    case 10760: /* module 42 call 7 */
    case 10761: /* module 42 call 8 */
    case 11520: /* module 45 call 0 */
    case 11521: /* module 45 call 1 */
    case 11776: /* module 46 call 0 */
    case 11777: /* module 46 call 1 */
    case 11778: /* module 46 call 2 */
    case 12032: /* module 47 call 0 */
    case 12288: /* module 48 call 0 */
    case 12289: /* module 48 call 1 */
    case 12290: /* module 48 call 2 */
    case 12291: /* module 48 call 3 */
    case 2560: // Democracy:Propose
    case 2561: // Democracy:Second
    case 2562: // Democracy:Vote
    case 2563: // Democracy:Emergency cancel
    case 2564: // Democracy:External propose
    case 2565: // Democracy:External propose majority
    case 2566: // Democracy:External propose default
    case 2567: // Democracy:Fast track
    case 2568: // Democracy:Veto external
    case 2571: // Democracy:Delegate
    case 2572: // Democracy:Undelegate
    case 2574: // Democracy:Note preimage
    case 2575: // Democracy:Note preimage operational
    case 2576: // Democracy:Note imminent preimage
    case 2577: // Democracy:Note imminent preimage operational
    case 2578: // Democracy:Reap preimage
    case 2579: // Democracy:Unlock
    case 2580: // Democracy:Remove vote
    case 2581: // Democracy:Remove other vote
    case 3328:
    case 3329:
    case 3331:
    case 7424:
    case 7425:
    case 7426:
    case 7427:
        return false;
    default:
        return true;
    }
}
