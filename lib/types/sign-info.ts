export interface SignInfo {
    filled: boolean;
    issuer: string;
    issuerCN: string;
    serial: string;
    subject: string;
    subjCN: string;
    subjOrg: string;
    subjOrgUnit: string;
    subjTitle: string;
    subjState: string;
    subjLocality: string;
    subjFullName: string;
    subjAddress: string;
    subjPhone: string;
    subjEMail: string;
    subjDNS: string;
    subjEDRPOUCode: string;
    subjDRFOCode: string;
    timeAvail: boolean;
    timeStamp: boolean;
    time: number;
}