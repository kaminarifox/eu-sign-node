import { SignInfo } from "./entity";

export interface VerifyDataInternalResult {
    signInfo: SignInfo,
    internalData: Buffer
}

