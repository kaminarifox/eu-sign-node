import { VerifyDataInternalResult } from "./types/result";

const addon = require("bindings")("eu-sign-node");

interface IEuSignNode {
    Initialize(osplmIniDir?: string): number;
    SetSettings(): number;
    VerifyDataInternal(data: Buffer): VerifyDataInternalResult
};

export class EuSignNode {
    constructor() {
        this._addonInstance = new addon.EuSignNode()
    }

    Initialize(osplmIniDir?: string): number {
        return this._addonInstance.Initialize(osplmIniDir);
    }

    SetSettings() {
        return this._addonInstance.SetSettings();
    }

    VerifyDataInternal(data: Buffer): VerifyDataInternalResult {
        return this._addonInstance.VerifyDataInternal(data)
    }

    // private members
    private _addonInstance: IEuSignNode;
}

module.exports = {
    EuSignNode
}