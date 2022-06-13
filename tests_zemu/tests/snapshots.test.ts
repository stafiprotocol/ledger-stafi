/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
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
 ******************************************************************************* */

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newStafiApp } from '@zondax/ledger-substrate'
import { APP_SEED } from './common'
import { txBalances_transfer, txStaking_nominate } from './zemu_blobs'
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";

const Resolve = require('path').resolve
const APP_PATH = Resolve('../app/output/app_sr25519.elf')
const SnapShotsPath =  Resolve('snapshots')

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(180000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

describe('SR25519', function () {
  test('s-mainmenu snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      // ready
      await sim.start({ ...defaultOptions })
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00000.png")
      // display expert mode
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00001.png")

      // enable expert mode
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00002.png")

      // disable expert mode
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00003.png")

      // version
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00004.png")
      // Developer
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00005.png")
      // license
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00006.png")
      // quit
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00007.png")

      // license
      await sim.clickLeft()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00008.png")
      // Developer
      await sim.clickLeft()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00009.png")
      // version
      await sim.clickLeft()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00010.png")
      // expert mode
      await sim.clickLeft()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00011.png")
      // ready
      await sim.clickLeft()
      await sim.snapshot(SnapShotsPath + "/s-mainmenu/00012.png")
    } finally {
      await sim.close()
    }
  })

  test('s-show_address snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions, model: 'nanos' })
      const app = newStafiApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.snapshot(SnapShotsPath + "/s-show_address/00000.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address/00001.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address/00002.png")
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-show_address/00003.png")
    } finally {
      await sim.close()
    }
  })

  test('s-show_address sr25519 snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions, model: 'nanos' })
      const app = newStafiApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.snapshot(SnapShotsPath + "/s-show_address_sr25519/00000.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_sr25519/00001.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_sr25519/00002.png")
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-show_address_sr25519/00003.png")
    } finally {
      await sim.close()
    }
  })

  test('s-show_address reject snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions, model: 'nanos' })
      const app = newStafiApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject_sr25519/00000.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject_sr25519/00001.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject_sr25519/00002.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject_sr25519/00003.png")
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject_sr25519/00004.png")
    } finally {
      await sim.close()
    }
  })

  test('s-show_address reject snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions, model: 'nanos' })
      const app = newStafiApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject/00000.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject/00001.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject/00002.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject/00003.png")
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-show_address_reject/00004.png")
    } finally {
      await sim.close()
    }
  })

  test('s-sign_basic_normal snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newStafiApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txBalances_transfer, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00000.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00001.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00002.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00003.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00004.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00005.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00006.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00007.png")
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_normal/00008.png")
    } finally {
      await sim.close()
    }
  })

  test('s-sign_basic_expert snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newStafiApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      // Change to expert mode so we can skip fields
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()

      const txBlob = Buffer.from(txBalances_transfer, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00000.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00001.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00002.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00003.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00004.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00005.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00006.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00007.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00008.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00009.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00010.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00011.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00012.png")
      await sim.clickRight()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00013.png")
      await sim.clickBoth()
      await sim.snapshot(SnapShotsPath + "/s-sign_basic_expert/00014.png")
    } finally {
      await sim.close()
    }
  })

  test('s-sign_large_nomination snapshots', async function () {
    const sim = new Zemu(APP_PATH)
    try {
      await sim.start({ ...defaultOptions })
      const app = newStafiApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txStaking_nominate, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', 's-sign_large_nomination')
    } finally {
      await sim.close()
    }
  })
})
