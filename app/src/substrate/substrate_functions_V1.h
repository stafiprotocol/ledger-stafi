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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V1.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V1(parser_context_t* c, pd_AccountId_V1_t* v);
parser_error_t _readAccountIndex_V1(parser_context_t* c, pd_AccountIndex_V1_t* v);
parser_error_t _readAccountVoteSplit_V1(parser_context_t* c, pd_AccountVoteSplit_V1_t* v);
parser_error_t _readAccountVoteStandard_V1(parser_context_t* c, pd_AccountVoteStandard_V1_t* v);
parser_error_t _readAccountVote_V1(parser_context_t* c, pd_AccountVote_V1_t* v);
parser_error_t _readAuthorityIdasRuntimeAppPublicSignature_V1(parser_context_t* c, pd_AuthorityIdasRuntimeAppPublicSignature_V1_t* v);
parser_error_t _readBoxCallOrHashOfT_V1(parser_context_t* c, pd_BoxCallOrHashOfT_V1_t* v);
parser_error_t _readBoxEquivocationProofHashBlockNumber_V1(parser_context_t* c, pd_BoxEquivocationProofHashBlockNumber_V1_t* v);
parser_error_t _readBoxEquivocationProofHeader_V1(parser_context_t* c, pd_BoxEquivocationProofHeader_V1_t* v);
parser_error_t _readBoxIdentityInfoMaxAdditionalFields_V1(parser_context_t* c, pd_BoxIdentityInfoMaxAdditionalFields_V1_t* v);
parser_error_t _readBoxMultiLocation_V1(parser_context_t* c, pd_BoxMultiLocation_V1_t* v);
parser_error_t _readBoxPalletsOrigin_V1(parser_context_t* c, pd_BoxPalletsOrigin_V1_t* v);
parser_error_t _readBoxRawSolutionSolutionOfT_V1(parser_context_t* c, pd_BoxRawSolutionSolutionOfT_V1_t* v);
parser_error_t _readBoxVersionedMultiAssets_V1(parser_context_t* c, pd_BoxVersionedMultiAssets_V1_t* v);
parser_error_t _readBoxVersionedMultiLocation_V1(parser_context_t* c, pd_BoxVersionedMultiLocation_V1_t* v);
parser_error_t _readBoxVersionedXcmTasSysConfigCall_V1(parser_context_t* c, pd_BoxVersionedXcmTasSysConfigCall_V1_t* v);
parser_error_t _readBoxVersionedXcmTuple_V1(parser_context_t* c, pd_BoxVersionedXcmTuple_V1_t* v);
parser_error_t _readCallHashOf_V1(parser_context_t* c, pd_CallHashOf_V1_t* v);
parser_error_t _readCompactAccountIndex_V1(parser_context_t* c, pd_CompactAccountIndex_V1_t* v);
parser_error_t _readCompactPerBill_V1(parser_context_t* c, pd_CompactPerBill_V1_t* v);
parser_error_t _readConfigOpBalanceOfT_V1(parser_context_t* c, pd_ConfigOpBalanceOfT_V1_t* v);
parser_error_t _readConfigOpPerbill_V1(parser_context_t* c, pd_ConfigOpPerbill_V1_t* v);
parser_error_t _readConfigOpPercent_V1(parser_context_t* c, pd_ConfigOpPercent_V1_t* v);
parser_error_t _readConfigOpu32_V1(parser_context_t* c, pd_ConfigOpu32_V1_t* v);
parser_error_t _readConviction_V1(parser_context_t* c, pd_Conviction_V1_t* v);
parser_error_t _readEcdsaSignature_V1(parser_context_t* c, pd_EcdsaSignature_V1_t* v);
parser_error_t _readElectionScore_V1(parser_context_t* c, pd_ElectionScore_V1_t* v);
parser_error_t _readEraIndex_V1(parser_context_t* c, pd_EraIndex_V1_t* v);
parser_error_t _readEthereumAddress_V1(parser_context_t* c, pd_EthereumAddress_V1_t* v);
parser_error_t _readHeadData_V1(parser_context_t* c, pd_HeadData_V1_t* v);
parser_error_t _readHeartbeatBlockNumber_V1(parser_context_t* c, pd_HeartbeatBlockNumber_V1_t* v);
parser_error_t _readHrmpChannelId_V1(parser_context_t* c, pd_HrmpChannelId_V1_t* v);
parser_error_t _readIdentityFields_V1(parser_context_t* c, pd_IdentityFields_V1_t* v);
parser_error_t _readJudgementBalanceOfT_V1(parser_context_t* c, pd_JudgementBalanceOfT_V1_t* v);
parser_error_t _readKeyOwnerProof_V1(parser_context_t* c, pd_KeyOwnerProof_V1_t* v);
parser_error_t _readKeyValue_V1(parser_context_t* c, pd_KeyValue_V1_t* v);
parser_error_t _readKey_V1(parser_context_t* c, pd_Key_V1_t* v);
parser_error_t _readKeys_V1(parser_context_t* c, pd_Keys_V1_t* v);
parser_error_t _readLeasePeriodOfT_V1(parser_context_t* c, pd_LeasePeriodOfT_V1_t* v);
parser_error_t _readLookupasStaticLookupSource_V1(parser_context_t* c, pd_LookupasStaticLookupSource_V1_t* v);
parser_error_t _readMemberCount_V1(parser_context_t* c, pd_MemberCount_V1_t* v);
parser_error_t _readMultiSignature_V1(parser_context_t* c, pd_MultiSignature_V1_t* v);
parser_error_t _readMultiSigner_V1(parser_context_t* c, pd_MultiSigner_V1_t* v);
parser_error_t _readNextConfigDescriptor_V1(parser_context_t* c, pd_NextConfigDescriptor_V1_t* v);
parser_error_t _readOpaqueCall_V1(parser_context_t* c, pd_OpaqueCall_V1_t* v);
parser_error_t _readOptionAccountId_V1(parser_context_t* c, pd_OptionAccountId_V1_t* v);
parser_error_t _readOptionElectionScore_V1(parser_context_t* c, pd_OptionElectionScore_V1_t* v);
parser_error_t _readOptionMultiSignature_V1(parser_context_t* c, pd_OptionMultiSignature_V1_t* v);
parser_error_t _readOptionMultiSigner_V1(parser_context_t* c, pd_OptionMultiSigner_V1_t* v);
parser_error_t _readOptionProxyType_V1(parser_context_t* c, pd_OptionProxyType_V1_t* v);
parser_error_t _readOptionReferendumIndex_V1(parser_context_t* c, pd_OptionReferendumIndex_V1_t* v);
parser_error_t _readOptionStatementKind_V1(parser_context_t* c, pd_OptionStatementKind_V1_t* v);
parser_error_t _readOptionTimepoint_V1(parser_context_t* c, pd_OptionTimepoint_V1_t* v);
parser_error_t _readOptionTupleBalanceOfTBalanceOfTBlockNumber_V1(parser_context_t* c, pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V1_t* v);
parser_error_t _readOptionXcmVersion_V1(parser_context_t* c, pd_OptionXcmVersion_V1_t* v);
parser_error_t _readOptionschedulePeriodBlockNumber_V1(parser_context_t* c, pd_OptionschedulePeriodBlockNumber_V1_t* v);
parser_error_t _readOverweightIndex_V1(parser_context_t* c, pd_OverweightIndex_V1_t* v);
parser_error_t _readParaId_V1(parser_context_t* c, pd_ParaId_V1_t* v);
parser_error_t _readParachainsInherentDataHeader_V1(parser_context_t* c, pd_ParachainsInherentDataHeader_V1_t* v);
parser_error_t _readPerbill_V1(parser_context_t* c, pd_Perbill_V1_t* v);
parser_error_t _readPercent_V1(parser_context_t* c, pd_Percent_V1_t* v);
parser_error_t _readProxyType_V1(parser_context_t* c, pd_ProxyType_V1_t* v);
parser_error_t _readPvfCheckStatement_V1(parser_context_t* c, pd_PvfCheckStatement_V1_t* v);
parser_error_t _readReferendumIndex_V1(parser_context_t* c, pd_ReferendumIndex_V1_t* v);
parser_error_t _readRegistrarIndex_V1(parser_context_t* c, pd_RegistrarIndex_V1_t* v);
parser_error_t _readRenouncing_V1(parser_context_t* c, pd_Renouncing_V1_t* v);
parser_error_t _readRewardDestination_V1(parser_context_t* c, pd_RewardDestination_V1_t* v);
parser_error_t _readSessionIndex_V1(parser_context_t* c, pd_SessionIndex_V1_t* v);
parser_error_t _readSolutionOrSnapshotSize_V1(parser_context_t* c, pd_SolutionOrSnapshotSize_V1_t* v);
parser_error_t _readStatementKind_V1(parser_context_t* c, pd_StatementKind_V1_t* v);
parser_error_t _readSupportsAccountId_V1(parser_context_t* c, pd_SupportsAccountId_V1_t* v);
parser_error_t _readTimepoint_V1(parser_context_t* c, pd_Timepoint_V1_t* v);
parser_error_t _readTupleAccountIdData_V1(parser_context_t* c, pd_TupleAccountIdData_V1_t* v);
parser_error_t _readTupleBalanceOfTBalanceOfTBlockNumber_V1(parser_context_t* c, pd_TupleBalanceOfTBalanceOfTBlockNumber_V1_t* v);
parser_error_t _readValidationCodeHash_V1(parser_context_t* c, pd_ValidationCodeHash_V1_t* v);
parser_error_t _readValidationCode_V1(parser_context_t* c, pd_ValidationCode_V1_t* v);
parser_error_t _readValidatorPrefs_V1(parser_context_t* c, pd_ValidatorPrefs_V1_t* v);
parser_error_t _readValidatorSignature_V1(parser_context_t* c, pd_ValidatorSignature_V1_t* v);
parser_error_t _readVecAccountId_V1(parser_context_t* c, pd_VecAccountId_V1_t* v);
parser_error_t _readVecKeyValue_V1(parser_context_t* c, pd_VecKeyValue_V1_t* v);
parser_error_t _readVecKey_V1(parser_context_t* c, pd_VecKey_V1_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V1(parser_context_t* c, pd_VecLookupasStaticLookupSource_V1_t* v);
parser_error_t _readVecTupleAccountIdData_V1(parser_context_t* c, pd_VecTupleAccountIdData_V1_t* v);
parser_error_t _readVestingInfo_V1(parser_context_t* c, pd_VestingInfo_V1_t* v);
parser_error_t _readVote_V1(parser_context_t* c, pd_Vote_V1_t* v);
parser_error_t _readWeightLimit_V1(parser_context_t* c, pd_WeightLimit_V1_t* v);
parser_error_t _readWeight_V1(parser_context_t* c, pd_Weight_V1_t* v);
parser_error_t _readXcmVersion_V1(parser_context_t* c, pd_XcmVersion_V1_t* v);
parser_error_t _readschedulePeriodBlockNumber_V1(parser_context_t* c, pd_schedulePeriodBlockNumber_V1_t* v);
parser_error_t _readschedulePriority_V1(parser_context_t* c, pd_schedulePriority_V1_t* v);

// toString functions
parser_error_t _toStringAccountId_V1(
    const pd_AccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V1(
    const pd_AccountIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteSplit_V1(
    const pd_AccountVoteSplit_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVoteStandard_V1(
    const pd_AccountVoteStandard_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountVote_V1(
    const pd_AccountVote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorityIdasRuntimeAppPublicSignature_V1(
    const pd_AuthorityIdasRuntimeAppPublicSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxCallOrHashOfT_V1(
    const pd_BoxCallOrHashOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHashBlockNumber_V1(
    const pd_BoxEquivocationProofHashBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxEquivocationProofHeader_V1(
    const pd_BoxEquivocationProofHeader_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxIdentityInfoMaxAdditionalFields_V1(
    const pd_BoxIdentityInfoMaxAdditionalFields_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxMultiLocation_V1(
    const pd_BoxMultiLocation_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin_V1(
    const pd_BoxPalletsOrigin_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxRawSolutionSolutionOfT_V1(
    const pd_BoxRawSolutionSolutionOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiAssets_V1(
    const pd_BoxVersionedMultiAssets_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedMultiLocation_V1(
    const pd_BoxVersionedMultiLocation_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTasSysConfigCall_V1(
    const pd_BoxVersionedXcmTasSysConfigCall_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxVersionedXcmTuple_V1(
    const pd_BoxVersionedXcmTuple_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCallHashOf_V1(
    const pd_CallHashOf_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V1(
    const pd_CompactAccountIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V1(
    const pd_CompactPerBill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpBalanceOfT_V1(
    const pd_ConfigOpBalanceOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPerbill_V1(
    const pd_ConfigOpPerbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpPercent_V1(
    const pd_ConfigOpPercent_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConfigOpu32_V1(
    const pd_ConfigOpu32_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConviction_V1(
    const pd_Conviction_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V1(
    const pd_EcdsaSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V1(
    const pd_ElectionScore_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V1(
    const pd_EraIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V1(
    const pd_EthereumAddress_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeadData_V1(
    const pd_HeadData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHeartbeatBlockNumber_V1(
    const pd_HeartbeatBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHrmpChannelId_V1(
    const pd_HrmpChannelId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityFields_V1(
    const pd_IdentityFields_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringJudgementBalanceOfT_V1(
    const pd_JudgementBalanceOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V1(
    const pd_KeyOwnerProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V1(
    const pd_KeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V1(
    const pd_Key_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V1(
    const pd_Keys_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeasePeriodOfT_V1(
    const pd_LeasePeriodOfT_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V1(
    const pd_LookupasStaticLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V1(
    const pd_MemberCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V1(
    const pd_MultiSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSigner_V1(
    const pd_MultiSigner_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNextConfigDescriptor_V1(
    const pd_NextConfigDescriptor_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOpaqueCall_V1(
    const pd_OpaqueCall_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAccountId_V1(
    const pd_OptionAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionElectionScore_V1(
    const pd_OptionElectionScore_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSignature_V1(
    const pd_OptionMultiSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMultiSigner_V1(
    const pd_OptionMultiSigner_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionProxyType_V1(
    const pd_OptionProxyType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReferendumIndex_V1(
    const pd_OptionReferendumIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionStatementKind_V1(
    const pd_OptionStatementKind_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTimepoint_V1(
    const pd_OptionTimepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTupleBalanceOfTBalanceOfTBlockNumber_V1(
    const pd_OptionTupleBalanceOfTBalanceOfTBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionXcmVersion_V1(
    const pd_OptionXcmVersion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionschedulePeriodBlockNumber_V1(
    const pd_OptionschedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOverweightIndex_V1(
    const pd_OverweightIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParaId_V1(
    const pd_ParaId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringParachainsInherentDataHeader_V1(
    const pd_ParachainsInherentDataHeader_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V1(
    const pd_Perbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V1(
    const pd_Percent_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProxyType_V1(
    const pd_ProxyType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPvfCheckStatement_V1(
    const pd_PvfCheckStatement_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReferendumIndex_V1(
    const pd_ReferendumIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRegistrarIndex_V1(
    const pd_RegistrarIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRenouncing_V1(
    const pd_Renouncing_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V1(
    const pd_RewardDestination_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSessionIndex_V1(
    const pd_SessionIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSolutionOrSnapshotSize_V1(
    const pd_SolutionOrSnapshotSize_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStatementKind_V1(
    const pd_StatementKind_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSupportsAccountId_V1(
    const pd_SupportsAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTimepoint_V1(
    const pd_Timepoint_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleAccountIdData_V1(
    const pd_TupleAccountIdData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleBalanceOfTBalanceOfTBlockNumber_V1(
    const pd_TupleBalanceOfTBalanceOfTBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCodeHash_V1(
    const pd_ValidationCodeHash_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidationCode_V1(
    const pd_ValidationCode_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V1(
    const pd_ValidatorPrefs_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorSignature_V1(
    const pd_ValidatorSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V1(
    const pd_VecAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V1(
    const pd_VecKeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V1(
    const pd_VecKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V1(
    const pd_VecLookupasStaticLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleAccountIdData_V1(
    const pd_VecTupleAccountIdData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVestingInfo_V1(
    const pd_VestingInfo_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVote_V1(
    const pd_Vote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeightLimit_V1(
    const pd_WeightLimit_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V1(
    const pd_Weight_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringXcmVersion_V1(
    const pd_XcmVersion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePeriodBlockNumber_V1(
    const pd_schedulePeriodBlockNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringschedulePriority_V1(
    const pd_schedulePriority_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
