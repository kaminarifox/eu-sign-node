#ifndef EU_SIGN_CP_H
#define EU_SIGN_CP_H

//=============================================================================

#include <dlfcn.h>
#include <string.h>
#include <unistd.h>

//-----------------------------------------------------------------------------

#include "EUError.h"

//=============================================================================

typedef struct _SYSTEMTIME
{
	unsigned short	wYear;
	unsigned short	wMonth;
	unsigned short	wDayOfWeek;
	unsigned short	wDay;
	unsigned short	wHour;
	unsigned short	wMinute;
	unsigned short	wSecond;
	unsigned short	wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

//-----------------------------------------------------------------------------

#pragma pack(push, 1)
typedef struct
{
	int			bFilled;

	char*		pszIssuer;
	char*		pszIssuerCN;
	char*		pszSerial;

	char*		pszSubject;
	char*		pszSubjCN;
	char*		pszSubjOrg;
	char*		pszSubjOrgUnit;
	char*		pszSubjTitle;
	char*		pszSubjState;
	char*		pszSubjLocality;
	char*		pszSubjFullName;
	char*		pszSubjAddress;
	char*		pszSubjPhone;
	char*		pszSubjEMail;
	char*		pszSubjDNS;
	char*		pszSubjEDRPOUCode;
	char*		pszSubjDRFOCode;
} EU_CERT_OWNER_INFO, *PEU_CERT_OWNER_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#ifdef OS_HPUX
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
	int			bFilled;

	char*		pszIssuer;
	char*		pszIssuerCN;
	char*		pszSerial;

	char*		pszSubject;
	char*		pszSubjCN;
	char*		pszSubjOrg;
	char*		pszSubjOrgUnit;
	char*		pszSubjTitle;
	char*		pszSubjState;
	char*		pszSubjLocality;
	char*		pszSubjFullName;
	char*		pszSubjAddress;
	char*		pszSubjPhone;
	char*		pszSubjEMail;
	char*		pszSubjDNS;
	char*		pszSubjEDRPOUCode;
	char*		pszSubjDRFOCode;

	int			bTimeAvail;
	int			bTimeStamp;
	SYSTEMTIME	Time;
} EU_SIGN_INFO, *PEU_SIGN_INFO,
  EU_ENVELOP_INFO, *PEU_ENVELOP_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#define EU_PASS_MAX_LENGTH		65

//-----------------------------------------------------------------------------

typedef struct
{
	unsigned long		dwTypeIndex, dwDevIndex;
	char		szPassword[EU_PASS_MAX_LENGTH];
} EU_KEY_MEDIA, *PEU_KEY_MEDIA;

//-----------------------------------------------------------------------------

#define EU_ERROR_MAX_LENGTH			1025
#define EU_SIGNER_INFO_MAX_LENGTH	1153

//-----------------------------------------------------------------------------

#define EU_KEY_MEDIA_NAME_MAX_LENGTH	257
#define EU_KEY_MEDIA_MAX_TYPES			32
#define EU_KEY_MEDIA_MAX_DEVICES		32

#define EU_KEY_MEDIA_SOURCE_TYPE_OPERATOR	1
#define EU_KEY_MEDIA_SOURCE_TYPE_FIXED		2

//-----------------------------------------------------------------------------

#define EU_PATH_MAX_LENGTH				1041

#define EU_ISSUER_MAX_LENGTH			1024
#define EU_SERIAL_MAX_LENGTH 			64
#define EU_COMMON_NAME_MAX_LENGTH		65
#define EU_COUNTRY_MAX_LENGTH			3
#define EU_LOCALITY_MAX_LENGTH			129
#define EU_STATE_MAX_LENGTH				129
#define EU_ORGANIZATION_MAX_LENGTH		65
#define EU_ORG_UNIT_MAX_LENGTH			65
#define EU_TITLE_MAX_LENGTH				65
#define EU_STREET_MAX_LENGTH			129
#define EU_PHONE_MAX_LENGTH				33
#define EU_SURNAME_MAX_LENGTH			41
#define EU_GIVENNAME_MAX_LENGTH			33
#define EU_EMAIL_MAX_LENGTH				129
#define EU_ADDRESS_MAX_LENGTH			257
#define EU_EDRPOU_MAX_LENGTH			11
#define EU_DRFO_MAX_LENGTH				11
#define EU_NBU_MAX_LENGTH				7
#define EU_SPFM_MAX_LENGTH				7
#define EU_O_CODE_MAX_LENGTH			33
#define EU_OU_CODE_MAX_LENGTH			33
#define EU_USER_CODE_MAX_LENGTH			33
#define EU_UPN_MAX_LENGTH				257
#define EU_UNZR_MAX_LENGTH				15

#define EU_PORT_MAX_LENGTH				6
#define EU_USER_NAME_MAX_LENGTH			65

#define EU_POLICIES_MAX_LENGTH			1025

#define EU_INFORMATION_MAX_LENGTH		513
#define EU_PASS_PHRASE_MAX_LENGTH		129

#define EU_TSL_ADDRESS_MAX_LENGTH		2561

//-----------------------------------------------------------------------------

#define EU_SUBJECT_TYPE_UNDIFFERENCED		0
#define EU_SUBJECT_TYPE_CA					1
#define EU_SUBJECT_TYPE_CA_SERVER			2
#define EU_SUBJECT_TYPE_RA_ADMINISTRATOR	3
#define EU_SUBJECT_TYPE_END_USER			4

#define EU_SUBJECT_CA_SERVER_SUB_TYPE_UNDIFFERENCED	0
#define EU_SUBJECT_CA_SERVER_SUB_TYPE_CMP			1
#define EU_SUBJECT_CA_SERVER_SUB_TYPE_TSP			2
#define EU_SUBJECT_CA_SERVER_SUB_TYPE_OCSP			3

//-----------------------------------------------------------------------------

#define EU_CERT_INFO_VERSION			1

#define EU_CERT_INFO_EX_VERSION_2		2
#define EU_CERT_INFO_EX_VERSION_3		3
#define EU_CERT_INFO_EX_VERSION_4		4
#define EU_CERT_INFO_EX_VERSION_5		5
#define EU_CERT_INFO_EX_VERSION_6		6
#define EU_CERT_INFO_EX_VERSION_7		7
#define EU_CERT_INFO_EX_VERSION_8		8
#define EU_CERT_INFO_EX_VERSION			9

#define EU_CRL_DETAILED_INFO_VERSION	1

#define EU_CR_INFO_VERSION_1			1
#define EU_CR_INFO_VERSION_2			2
#define EU_CR_INFO_VERSION_3			3
#define EU_CR_INFO_VERSION				4

#define EU_USER_INFO_VERSION_1			1
#define EU_USER_INFO_VERSION_2			2
#define EU_USER_INFO_VERSION			3

#define EU_USER_PARAMS_VERSION			1

#define EU_SCC_STATISTIC_VERSION		1

#define EU_TIME_INFO_VERSION_1			1
#define EU_TIME_INFO_VERSION			2

#define EU_KEY_MEDIA_DEVICE_INFO_VERSION	1

#define EU_SS_SIGN_HASH_RESULT_VERSION	1

//-----------------------------------------------------------------------------

#define EU_CERT_KEY_TYPE_UNKNOWN		0x00
#define	EU_CERT_KEY_TYPE_DSTU4145		0x01
#define	EU_CERT_KEY_TYPE_RSA			0x02
#define EU_CERT_KEY_TYPE_ECDSA			0x04

//-----------------------------------------------------------------------------

#define EU_CERT_HASH_TYPE_UNKNOWN		0x00
#define EU_CERT_HASH_TYPE_GOST34311		0x01
#define EU_CERT_HASH_TYPE_SHA1			0x02
#define EU_CERT_HASH_TYPE_SHA224		0x03
#define EU_CERT_HASH_TYPE_SHA256		0x04
#define EU_CERT_HASH_TYPE_SHA384		0x05
#define EU_CERT_HASH_TYPE_SHA512		0x06
#define EU_CERT_HASH_TYPE_DSTU7564_256	0x07
#define EU_CERT_HASH_TYPE_DSTU7564_384	0x08
#define EU_CERT_HASH_TYPE_DSTU7564_512	0x09

//-----------------------------------------------------------------------------

#define EU_KEY_USAGE_UNKNOWN			0x0000
#define EU_KEY_USAGE_DIGITAL_SIGNATURE	0x0001
#define EU_KEY_USAGE_NON_REPUDATION		0x0002
#define EU_KEY_USAGE_KEY_AGREEMENT		0x0010

//-----------------------------------------------------------------------------

#define EU_KEYS_TYPE_NONE						0
#define EU_KEYS_TYPE_DSTU_AND_ECDH_WITH_GOSTS	1
#define EU_KEYS_TYPE_RSA_WITH_SHA				2
#define EU_KEYS_TYPE_ECDSA_WITH_SHA				4
#define EU_KEYS_TYPE_DSTU_AND_ECDH_WITH_DSTU	8

//-----------------------------------------------------------------------------

#define EU_KEYS_LENGTH_DS_UA_191		1
#define EU_KEYS_LENGTH_DS_UA_257		2
#define EU_KEYS_LENGTH_DS_UA_307		3
#define EU_KEYS_LENGTH_DS_UA_FILE		4
#define EU_KEYS_LENGTH_DS_UA_CERT		5

#define EU_KEYS_LENGTH_KEP_UA_257		1
#define EU_KEYS_LENGTH_KEP_UA_431		2
#define EU_KEYS_LENGTH_KEP_UA_571		3
#define EU_KEYS_LENGTH_KEP_UA_FILE		4
#define EU_KEYS_LENGTH_KEP_UA_CERT		5

#define EU_KEYS_LENGTH_DS_RSA_1024		1
#define EU_KEYS_LENGTH_DS_RSA_2048		2
#define EU_KEYS_LENGTH_DS_RSA_3072		3
#define EU_KEYS_LENGTH_DS_RSA_4096		4
#define EU_KEYS_LENGTH_DS_FILE			5
#define EU_KEYS_LENGTH_DS_RSA_FILE		EU_KEYS_LENGTH_DS_FILE
#define EU_KEYS_LENGTH_DS_RSA_CERT		6

#define EU_KEYS_LENGTH_DS_ECDSA_192		1
#define EU_KEYS_LENGTH_DS_ECDSA_256		2
#define EU_KEYS_LENGTH_DS_ECDSA_384		3
#define EU_KEYS_LENGTH_DS_ECDSA_521		4
#define EU_KEYS_LENGTH_DS_ECDSA_FILE	EU_KEYS_LENGTH_DS_FILE
#define EU_KEYS_LENGTH_DS_ECDSA_CERT	6

//-----------------------------------------------------------------------------

#define EU_DEFAULT_LANG					0
#define EU_UA_LANG						1
#define EU_RU_LANG						2
#define EU_EN_LANG						3

//-----------------------------------------------------------------------------

#define EU_CP_ACP_ENCODING				0
#define EU_CP_1251_ENCODING				1251
#define EU_UTF8_ENCODING				65001

//-----------------------------------------------------------------------------

#define EU_RESOLVE_OIDS_PARAMETER			"ResolveOIDs"
#define EU_RESOLVE_OIDS_PARAMETER_LENGTH	4

#define EU_SAVE_SETTINGS_PARAMETER			"SaveSettings"
#define EU_SAVE_SETTINGS_PARAMETER_LENGTH	4

#define EU_UI_MODE_PARAMETER				"UIMode"
#define EU_UI_MODE_LENGTH					4

#define EU_SHOW_ERRORS_PARAMETER			"ShowErrors"
#define EU_SHOW_ERRORS_LENGTH				4

#define EU_MAKE_PKEY_PFX_CONTAINER_PARAMETER	"MakePKeyPFXContainer"
#define EU_MAKE_PKEY_PFX_CONTAINER_LENGTH	4

#define EU_NO_CSP_SELF_TESTS_PARAMETER		"NoCSPSelfTests"
#define EU_NO_CSP_SELF_TESTS_LENGTH			4

#define EU_SIGN_INCLUDE_CONTENT_TIME_STAMP_PARAMETER	\
											"SignIncludeContentTimeStamp"
#define EU_SIGN_INCLUDE_CONTENT_TIME_STAMP_LENGTH	4

#define EU_SIGN_TYPE_PARAMETER				"SignType"
#define EU_SIGN_TYPE_LENGTH					4

#define EU_SIGN_INCLUDE_CA_CERTIFICATES_PARAMETER		\
											"SignIncludeCACertificates"
#define EU_SIGN_INCLUDE_CA_CERTIFICATES_LENGTH		4

#define EU_FS_CALCULATE_FINGERPRINT			"FSCalculateFingerprint"
#define EU_FS_CALCULATE_FINGERPRINT_LENGTH	4

#define EU_FP_RESET							"FPReset"
#define EU_FP_RESET_LENGTH					4

#define EU_PROXY_TYPE						"ProxyType"
#define EU_PROXY_TYPE_LENGTH				4

#define EU_KM_SOFTWARE_MODE_PARAMETER		"KMSoftwareMode"
#define EU_KM_SOFTWARE_MODE_LENGTH			4

#define EU_FORBID_CHDIR_PARAMETER			"ForbidChdir"
#define EU_FORBID_CHDIR_LENGTH				4

#define EU_RETURN_NAMED_KEY_ERROR_PARAMETER			"ReturnNamedKeyError"
#define EU_RETURN_NAMED_KEY_ERROR_PARAMETER_LENGTH	4

#define EU_FORCE_USE_TSP_FROM_SETTINGS_PARAMETER	\
											"ForceUseTSPFromSettings"
#define EU_FORCE_USE_TSP_FROM_SETTINGS_PARAMETER_LENGTH	4

#define EU_LOG_ENCODING_PARAMETER			"LogEncoding"
#define EU_LOG_ENCODING_PARAMETER_LENGTH	4

#define EU_STRING_ENCODING_PARAMETER			"StringEncoding"
#define EU_STRING_ENCODING_PARAMETER_LENGTH	4

#define EU_USE_UTC_TIME_PARAMETER			"UseUTCTime"
#define EU_USE_UTC_TIME_PARAMETER_LENGTH	4

#define EU_CHECK_CERT_CHAIN_ON_SIGN_TIME_PARAMETER	\
											"CheckCertChainOnSignTime"
#define EU_CHECK_CERT_CHAIN_ON_SIGN_TIME_PARAMETER_LENGTH	4

#define EU_CONNECTIONS_TIMEOUT_PARAMETER			"ConnectionsTimeout"
#define EU_CONNECTIONS_TIMEOUT_PARAMETER_LENGTH		4

#define EU_LOG_EVENTS_THRESHOLD_PARAMETER			"LogEventsThreshold"
#define EU_LOG_EVENTS_THRESHOLD_PARAMETER_LENGTH	4

//-----------------------------------------------------------------------------

#define EU_RECIPIENT_APPEND_TYPE_BY_ISSUER_SERIAL	1
#define EU_RECIPIENT_APPEND_TYPE_BY_KEY_ID			2

//-----------------------------------------------------------------------------

#define EU_STORAGE_VALUE_MAX_LENGTH					0x7FFF

//-----------------------------------------------------------------------------

#define EU_SETTINGS_ID_NONE							0x000
#define EU_SETTINGS_ID_ALL							0xFFF

#define EU_SETTINGS_ID_FSTORE						0x001
#define EU_SETTINGS_ID_PROXY						0x002
#define EU_SETTINGS_ID_TSP							0x004
#define EU_SETTINGS_ID_OCSP							0x008
#define EU_SETTINGS_ID_LDAP							0x010

#define EU_SETTINGS_ID_MANDATORY					0x01F

#define EU_SETTINGS_ID_MODE							0x020
#define EU_SETTINGS_ID_CMP							0x040
#define EU_SETTINGS_ID_KM							0x080

#define EU_SETTINGS_ID_OCSP_ACCESS_INFO_MODE		0x100
#define EU_SETTINGS_ID_OCSP_ACCESS_INFO				0x200
#define EU_SETTINGS_ID_TSL							0x400
#define EU_SETTINGS_ID_LOG							0x800

//-----------------------------------------------------------------------------

#define EU_OCSP_SERVER_STATE_UNKNOWN				0
#define EU_OCSP_SERVER_STATE_AVAILABLE				1
#define EU_OCSP_SERVER_STATE_UNAVAILABLE			2

//-----------------------------------------------------------------------------

#define EU_SIGN_TYPE_UNKNOWN						0
#define EU_SIGN_TYPE_CADES_BES						1
#define EU_SIGN_TYPE_CADES_T						4
#define EU_SIGN_TYPE_CADES_C						8
#define EU_SIGN_TYPE_CADES_X_LONG					16
#define EU_SIGN_TYPE_CADES_X_LONG_TRUSTED			128

//-----------------------------------------------------------------------------

#define EU_PROXY_TYPE_UNKNOWN						0x0000
#define EU_PROXY_TYPE_SETTINGS						0x0001
#define EU_PROXY_TYPE_SYSTEM						0x0002

//-----------------------------------------------------------------------------

#define EU_CHECK_PRIVATE_KEY_CONTEXT_PARAMETER		"CheckPrivateKey"
#define EU_CHECK_PRIVATE_KEY_CONTEXT_PARAMETER_LENGTH	4

#define EU_RESOLVE_OIDS_CONTEXT_PARAMETER			"ResolveOIDs"
#define EU_RESOLVE_OIDS_CONTEXT_PARAMETER_LENGTH		4

#define EU_EXPORATABLE_CONTEXT_CONTEXT_PARAMETER	"ExportableContext"
#define EU_EXPORATABLE_CONTEXT_CONTEXT_PARAMETER_LENGTH	4

#define EU_USE_COUPLE_PRIVATE_KEY_CONTEXT_PARAMETER	"UseCouplePrivateKey"
#define EU_USE_COUPLE_PRIVATE_KEY_CONTEXT_PARAMETER_LENGTH	4

//-----------------------------------------------------------------------------

#define	EU_RECIPIENT_INFO_TYPE_ISSUER_SERIAL		1
#define	EU_RECIPIENT_INFO_TYPE_KEY_ID				2

//-----------------------------------------------------------------------------

#define EU_CTX_HASH_ALGO_UNKNOWN				0
#define EU_CTX_HASH_ALGO_GOST34311				1
#define EU_CTX_HASH_ALGO_SHA160					2
#define EU_CTX_HASH_ALGO_SHA224					3
#define EU_CTX_HASH_ALGO_SHA256					4
#define EU_CTX_HASH_ALGO_SHA384					5
#define EU_CTX_HASH_ALGO_SHA512					6
#define EU_CTX_HASH_ALGO_DSTU7564_256			7
#define EU_CTX_HASH_ALGO_DSTU7564_384			8
#define EU_CTX_HASH_ALGO_DSTU7564_512			9

#define EU_CTX_SIGN_UNKNOWN						0
#define EU_CTX_SIGN_DSTU4145_WITH_GOST34311		1
#define EU_CTX_SIGN_RSA_WITH_SHA				2
#define EU_CTX_SIGN_ECDSA_WITH_SHA				3
#define EU_CTX_SIGN_DSTU4145_WITH_DSTU7564		4

//-----------------------------------------------------------------------------

#define EU_REG_KEY_ROOT_PATH_DEFAULT			0
#define EU_REG_KEY_ROOT_PATH_HKLM				1
#define EU_REG_KEY_ROOT_PATH_HKCU				2
#define EU_REG_KEY_ROOT_PATH_CURRENT			3

//-----------------------------------------------------------------------------

#define EU_CONTENT_ENC_ALGO_DEFAULT				0
#define EU_CONTENT_ENC_ALGO_GOST28147_CFB		2
#define EU_CONTENT_ENC_ALGO_TDES_CBC			4
#define EU_CONTENT_ENC_ALGO_AES_128_CBC			5
#define EU_CONTENT_ENC_ALGO_AES_192_CBC			6
#define EU_CONTENT_ENC_ALGO_AES_256_CBC			7
#define EU_CONTENT_ENC_ALGO_DSTU7624_256_OFB	8
#define EU_CONTENT_ENC_ALGO_DSTU7624_256_CFB	9

//-----------------------------------------------------------------------------

#define EU_DEV_CTX_MIN_PUBLIC_DATA_ID			0x10
#define EU_DEV_CTX_MAX_PUBLIC_DATA_ID			0x4F
#define EU_DEV_CTX_MIN_CONST_PUBLIC_DATA_ID		0x50
#define EU_DEV_CTX_MAX_CONST_PUBLIC_DATA_ID		0x6F
#define EU_DEV_CTX_MIN_CONST_PRIVATE_DATA_ID	0x70
#define EU_DEV_CTX_MAX_CONST_PRIVATE_DATA_ID	0x8F
#define EU_DEV_CTX_MIN_PRIVATE_DATA_ID			0x90
#define EU_DEV_CTX_MAX_PRIVATE_DATA_ID			0xAF

#define EU_DEV_CTX_DATA_ID_SERIAL_NUMBER		0xD1
#define EU_DEV_CTX_DATA_ID_SYSTEM_KEY_VERSION	0xD4
#define EU_DEV_CTX_DATA_ID_UPDATE_COUNTER		0xD6

#define EU_DEV_CTX_SYSTEM_KEY_TYPE_INDEX		0
#define EU_DEV_CTX_SYSTEM_KEY_VERSION_INDEX		1

//-----------------------------------------------------------------------------

#define EU_HEADER_CA_TYPE						"UA1"
#define EU_HEADER_PART_TYPE_SIGNED				1
#define EU_HEADER_PART_TYPE_ENCRYPTED			2
#define EU_HEADER_PART_TYPE_STAMPED				3
#define EU_HEADER_PART_TYPE_CERTCRYPT			4

#define EU_HEADER_MAX_CA_TYPE_SIZE				3

//-----------------------------------------------------------------------------

#define EU_CCS_TYPE_REVOKE						1
#define EU_CCS_TYPE_HOLD						2

//-----------------------------------------------------------------------------

#define EU_REVOCATION_REASON_UNKNOWN			0
#define EU_REVOCATION_REASON_KEY_COMPROMISE		1
#define EU_REVOCATION_REASON_NEW_ISSUED			2

//-----------------------------------------------------------------------------

#define EU_DEV_CTX_IDCARD_PASSWORD_VERSION_1	1
#define EU_DEV_CTX_IDCARD_PASSWORD_VERSION_2	2

//------------------------------------------------------------------------------

#define EU_DEV_CTX_IDCARD_DG32_DATA_ID			0x20
#define EU_DEV_CTX_IDCARD_DG33_DATA_ID			0x21
#define EU_DEV_CTX_IDCARD_DG34_DATA_ID			0x22
#define EU_DEV_CTX_IDCARD_DG35_DATA_ID			0x23
#define EU_DEV_CTX_IDCARD_DG36_DATA_ID			0x24
#define EU_DEV_CTX_IDCARD_DG37_DATA_ID			0x25
#define EU_DEV_CTX_IDCARD_DG38_DATA_ID			0x26

//------------------------------------------------------------------------------

#define EU_NAMED_PRIVATE_KEY_LABEL_MAX_LENGTH	64

//------------------------------------------------------------------------------

#define EU_DEV_CTX_IDCARD_COM_DATA_ID			0x1E

#define EU_DEV_CTX_IDCARD_DG1_DATA_ID			0x01
#define EU_DEV_CTX_IDCARD_DG2_DATA_ID			0x02
#define EU_DEV_CTX_IDCARD_DG3_DATA_ID			0x03
#define EU_DEV_CTX_IDCARD_DG4_DATA_ID			0x04
#define EU_DEV_CTX_IDCARD_DG5_DATA_ID			0x05
#define EU_DEV_CTX_IDCARD_DG6_DATA_ID			0x06
#define EU_DEV_CTX_IDCARD_DG7_DATA_ID			0x07
#define EU_DEV_CTX_IDCARD_DG8_DATA_ID			0x08
#define EU_DEV_CTX_IDCARD_DG9_DATA_ID			0x09
#define EU_DEV_CTX_IDCARD_DG10_DATA_ID			0x0A
#define EU_DEV_CTX_IDCARD_DG11_DATA_ID			0x0B
#define EU_DEV_CTX_IDCARD_DG12_DATA_ID			0x0C
#define EU_DEV_CTX_IDCARD_DG13_DATA_ID			0x0D
#define EU_DEV_CTX_IDCARD_DG14_DATA_ID			0x0E
#define EU_DEV_CTX_IDCARD_DG15_DATA_ID			0x0F
#define EU_DEV_CTX_IDCARD_DG16_DATA_ID			0x10
#define EU_DEV_CTX_IDCARD_DG17_DATA_ID			0x11
#define EU_DEV_CTX_IDCARD_DG18_DATA_ID			0x12

#define EU_DEV_CTX_IDCARD_SOD_DATA_ID			0x1D

#define EU_DEV_CTX_IDCARD_EID_DATA_ID_MASK		0x80

//------------------------------------------------------------------------------

#define EU_DEV_CTX_IDCARD_AA_NONCE_LENGTH		8

//------------------------------------------------------------------------------

#define EU_DEV_CTX_IDCARD_UNDEFINED_TERMINAL			0x00
#define EU_DEV_CTX_IDCARD_AUTHENTICATION_TERMINAL		0x01
#define EU_DEV_CTX_IDCARD_SIGNATURE_TERMINAL			0x02
#define EU_DEV_CTX_IDCARD_INSPECTION_TERMINAL			0x03

//------------------------------------------------------------------------------

#define EU_DEV_CTX_IDCARD_PASSWORD_UNDEFINED			0x00
#define EU_DEV_CTX_IDCARD_PASSWORD_MRZ					0x01
#define EU_DEV_CTX_IDCARD_PASSWORD_CAN					0x02
#define EU_DEV_CTX_IDCARD_PASSWORD_PIN					0x03
#define EU_DEV_CTX_IDCARD_PASSWORD_PUK					0x04

//------------------------------------------------------------------------------

#define EU_ASIC_TYPE_UNKNOWN		0
#define EU_ASIC_TYPE_S				1
#define EU_ASIC_TYPE_E				2

#define EU_ASIC_SIGN_TYPE_UNKNOWN	0
#define EU_ASIC_SIGN_TYPE_CADES		1
#define EU_ASIC_SIGN_TYPE_XADES		2

#define EU_ASIC_SIGN_LEVEL_BES		1
#define EU_ASIC_SIGN_LEVEL_T		4

//------------------------------------------------------------------------------

#define EU_ZIP_MIN_COMPRESSION_LEVEL			0
#define EU_ZIP_MAX_COMPRESSION_LEVEL			9

//------------------------------------------------------------------------------

#define EU_XADES_TYPE_UNKNOWN		0
#define EU_XADES_TYPE_DETACHED		1
#define EU_XADES_TYPE_ENVELOPING	2
#define EU_XADES_TYPE_ENVELOPED		3

#define EU_XADES_SIGN_LEVEL_UNKNOWN	0
#define EU_XADES_SIGN_LEVEL_B_B		1
#define EU_XADES_SIGN_LEVEL_B_T		4
#define EU_XADES_SIGN_LEVEL_B_LT	16
#define EU_XADES_SIGN_LEVEL_B_LTA	32

#define EU_XADES_SIGN_LEVEL_BES		EU_XADES_SIGN_LEVEL_B_B
#define EU_XADES_SIGN_LEVEL_T		EU_XADES_SIGN_LEVEL_B_T

//------------------------------------------------------------------------------

#define EU_PADES_SIGN_LEVEL_UNKNOWN	0
#define EU_PADES_SIGN_LEVEL_B_B		1
#define EU_PADES_SIGN_LEVEL_B_T		4
#define EU_PADES_SIGN_LEVEL_B_LT	16
#define EU_PADES_SIGN_LEVEL_B_LTA	32

//------------------------------------------------------------------------------

#define EU_CLIENT_CTX_MAX_PASSWORD_LENGTH		63
#define EU_CLIENT_CTX_MAX_NAME_LENGTH			63
#define EU_CLIENT_CTX_MAX_LOGIN_LENGTH			31
#define EU_CLIENT_CTX_MAX_IP_ADDRESS_LENGTH		15

#define EU_CLIENT_CTX_TYPE_ADMINISTRATOR		1
#define EU_CLIENT_CTX_TYPE_OPERATOR				2
#define EU_CLIENT_CTX_TYPE_BOTH					3

//------------------------------------------------------------------------------

#define EU_SESSION_ENC_ALGO_GOST28147			0
#define EU_SESSION_ENC_ALGO_DSTU7624_256		1
#define EU_SESSION_ENC_ALGO_DSTU7624_512		2
#define EU_SESSION_ENC_ALGO_DSTU8845_256		3
#define EU_SESSION_ENC_ALGO_DSTU8845_512		4

//------------------------------------------------------------------------------

#define EU_ALGO_DSTU7624_CFB_256		1

#define EU_ALGO_DSTU7624_KEY_256_LENGTH	32
#define EU_ALGO_DSTU7624_IV_256_LENGTH	32

#define EU_ALGO_DSTU7624_MAC_64_LENGTH	8
#define EU_ALGO_DSTU7624_MAC_128_LENGTH	16
#define EU_ALGO_DSTU7624_MAC_256_LENGTH	32

//------------------------------------------------------------------------------

#define EU_SS_REG_TOKEN_NAME_MAX_LENGTH					65

//------------------------------------------------------------------------------

#define EU_NBU_SIGNATURE_LENGTH					64

//------------------------------------------------------------------------------

#define EU_DEV_CTX_IS_KEYS_TYPE_RSA_1024		0x11
#define EU_DEV_CTX_IS_KEYS_TYPE_RSA_1536		0x12
#define EU_DEV_CTX_IS_KEYS_TYPE_RSA_2048		0x13
#define EU_DEV_CTX_IS_KEYS_TYPE_RSA_3072		0x14
#define EU_DEV_CTX_IS_KEYS_TYPE_RSA_4096		0x15

//------------------------------------------------------------------------------

#define EU_DEV_CTX_IS_KEYS_TYPE_EC_192			0x21
#define EU_DEV_CTX_IS_KEYS_TYPE_EC_224			0x22
#define EU_DEV_CTX_IS_KEYS_TYPE_EC_256			0x23
#define EU_DEV_CTX_IS_KEYS_TYPE_EC_384			0x24
#define EU_DEV_CTX_IS_KEYS_TYPE_EC_512			0x25
#define EU_DEV_CTX_IS_KEYS_TYPE_EC_521			0x26

//------------------------------------------------------------------------------

#ifdef OS_HPUX
#pragma pack(push, 8)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
	int			bFilled;

	char*		pszIssuer;
	char*		pszIssuerCN;

	unsigned long		dwCRLNumber;
	SYSTEMTIME	stThisUpdate;
	SYSTEMTIME	stNextUpdate;
} EU_CRL_INFO, *PEU_CRL_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#ifdef OS_HPUX
#pragma pack(push, 8)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
	int			bFilled;

	unsigned long		dwVersion;

	char*		pszIssuer;
	char*		pszIssuerCN;
	char*		pszSerial;

	char*		pszSubject;
	char*		pszSubjCN;
	char*		pszSubjOrg;
	char*		pszSubjOrgUnit;
	char*		pszSubjTitle;
	char*		pszSubjState;
	char*		pszSubjLocality;
	char*		pszSubjFullName;
	char*		pszSubjAddress;
	char*		pszSubjPhone;
	char*		pszSubjEMail;
	char*		pszSubjDNS;
	char*		pszSubjEDRPOUCode;
	char*		pszSubjDRFOCode;

	char*		pszSubjNBUCode;
	char*		pszSubjSPFMCode;
	char*		pszSubjOCode;
	char*		pszSubjOUCode;
	char*		pszSubjUserCode;

	SYSTEMTIME	stCertBeginTime;
	SYSTEMTIME	stCertEndTime;
	int			bPrivKeyTimes;
	SYSTEMTIME	stPrivKeyBeginTime;
	SYSTEMTIME	stPrivKeyEndTime;

	unsigned long		dwPublicKeyBits;
	char*		pszPublicKey;
	char*		pszPublicKeyID;

	int			bECDHPublicKey;
	unsigned long		dwECDHPublicKeyBits;
	char*		pszECDHPublicKey;
	char*		pszECDHPublicKeyID;

	char*		pszIssuerPublicKeyID;

	char*		pszKeyUsage;
	char*		pszExtKeyUsages;
	char*		pszPolicies;

	char*		pszCRLDistribPoint1;
	char*		pszCRLDistribPoint2;

	int			bPowerCert;

	int			bSubjType;
	int			bSubjCA;
} EU_CERT_INFO, *PEU_CERT_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#ifdef OS_HPUX
#pragma pack(push, 8)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
	int			bFilled;

	unsigned long		dwVersion;

	char*		pszIssuer;
	char*		pszIssuerCN;
	char*		pszSerial;

	char*		pszSubject;
	char*		pszSubjCN;
	char*		pszSubjOrg;
	char*		pszSubjOrgUnit;
	char*		pszSubjTitle;
	char*		pszSubjState;
	char*		pszSubjLocality;
	char*		pszSubjFullName;
	char*		pszSubjAddress;
	char*		pszSubjPhone;
	char*		pszSubjEMail;
	char*		pszSubjDNS;
	char*		pszSubjEDRPOUCode;
	char*		pszSubjDRFOCode;

	char*		pszSubjNBUCode;
	char*		pszSubjSPFMCode;
	char*		pszSubjOCode;
	char*		pszSubjOUCode;
	char*		pszSubjUserCode;

	SYSTEMTIME	stCertBeginTime;
	SYSTEMTIME	stCertEndTime;
	int			bPrivKeyTimes;
	SYSTEMTIME	stPrivKeyBeginTime;
	SYSTEMTIME	stPrivKeyEndTime;

	unsigned long		dwPublicKeyBits;
	char*		pszPublicKey;
	char*		pszPublicKeyID;

	char*		pszIssuerPublicKeyID;

	char*		pszKeyUsage;
	char*		pszExtKeyUsages;
	char*		pszPolicies;

	char*		pszCRLDistribPoint1;
	char*		pszCRLDistribPoint2;

	int			bPowerCert;

	int			bSubjType;
	int			bSubjCA;

	int			iChainLength;

	char*		pszUPN;

	unsigned long		dwPublicKeyType;
	unsigned long		dwKeyUsage;

	char*		pszRSAModul;
	char*		pszRSAExponent;

	char*		pszOCSPAccessInfo;
	char*		pszIssuerAccessInfo;
	char*		pszTSPAccessInfo;

	int			bLimitValueAvailable;
	unsigned long		dwLimitValue;
	char*		pszLimitValueCurrency;

	unsigned long		dwSubjType;
	unsigned long		dwSubjSubType;

	char*		pszSubjUNZR;

	char*		pszSubjCountry;

	char*		pszFingerprint;

	int			bQSCD;

	char*		pszSubjUserID;

	unsigned long		dwCertHashType;
} EU_CERT_INFO_EX, *PEU_CERT_INFO_EX, **PPEU_CERT_INFO_EX;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#ifdef OS_HPUX
#pragma pack(push, 8)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
	int			bFilled;

	unsigned long		dwVersion;

	char*		pszIssuer;
	char*		pszIssuerCN;
	char*		pszIssuerPublicKeyID;

	unsigned long		dwCRLNumber;
	SYSTEMTIME	stThisUpdate;
	SYSTEMTIME	stNextUpdate;

	unsigned long		dwRevokedItemsCount;
} EU_CRL_DETAILED_INFO, *PEU_CRL_DETAILED_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#pragma pack(push, 1)
typedef struct
{
	unsigned long		dwCount;
	
	PEU_CERT_INFO_EX 
				*ppCertificates;

} EU_CERTIFICATES, *PEU_CERTIFICATES, **PPEU_CERTIFICATES;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#ifdef OS_HPUX
#pragma pack(push, 8)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
	int			bFilled;

	unsigned long		dwVersion;

	int			bSimple;

	char*		pszSubject;
	char*		pszSubjCN;
	char*		pszSubjOrg;
	char*		pszSubjOrgUnit;
	char*		pszSubjTitle;
	char*		pszSubjState;
	char*		pszSubjLocality;
	char*		pszSubjFullName;
	char*		pszSubjAddress;
	char*		pszSubjPhone;
	char*		pszSubjEMail;
	char*		pszSubjDNS;
	char*		pszSubjEDRPOUCode;
	char*		pszSubjDRFOCode;
	char*		pszSubjNBUCode;
	char*		pszSubjSPFMCode;
	char*		pszSubjOCode;
	char*		pszSubjOUCode;
	char*		pszSubjUserCode;

	int			bCertTimes;
	SYSTEMTIME	stCertBeginTime;
	SYSTEMTIME	stCertEndTime;
	int			bPrivKeyTimes;
	SYSTEMTIME	stPrivKeyBeginTime;
	SYSTEMTIME	stPrivKeyEndTime;

	unsigned long		dwPublicKeyType;

	unsigned long		dwPublicKeyBits;
	char*		pszPublicKey;
	char*		pszRSAModul;
	char*		pszRSAExponent;

	char*		pszPublicKeyID;

	char*		pszExtKeyUsages;

	char*		pszCRLDistribPoint1;
	char*		pszCRLDistribPoint2;

	int			bSubjType;
	unsigned long		dwSubjType;
	unsigned long		dwSubjSubType;

	int			bSelfSigned;
	char*		pszSignIssuer;
	char*		pszSignSerial;

	char*		pszSubjUNZR;

	char*		pszSubjCountry;

	int			bQSCD;
} EU_CR_INFO, *PEU_CR_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#pragma pack(push, 1)
typedef struct
{
	unsigned long		dwVersion;

	char		szCommonName[EU_COMMON_NAME_MAX_LENGTH];
	char		szLocality[EU_LOCALITY_MAX_LENGTH];
	char		szState[EU_STATE_MAX_LENGTH];
	char		szOrganiztion[EU_ORGANIZATION_MAX_LENGTH];
	char		szOrgUnit[EU_ORG_UNIT_MAX_LENGTH];
	char		szTitle[EU_TITLE_MAX_LENGTH];
	char		szStreet[EU_STREET_MAX_LENGTH];
	char		szPhone[EU_PHONE_MAX_LENGTH];
	char		szSurname[EU_SURNAME_MAX_LENGTH];
	char		szGivenname[EU_GIVENNAME_MAX_LENGTH];
	char		szEMail[EU_EMAIL_MAX_LENGTH];
	char		szDNS[EU_ADDRESS_MAX_LENGTH];
	char		szEDRPOUCode[EU_EDRPOU_MAX_LENGTH];
	char		szDRFOCode[EU_DRFO_MAX_LENGTH];
	char		szNBUCode[EU_NBU_MAX_LENGTH];
	char		szSPFMCode[EU_SPFM_MAX_LENGTH];
	char		szOCode[EU_O_CODE_MAX_LENGTH];
	char		szOUCode[EU_OU_CODE_MAX_LENGTH];
	char		szUserCode[EU_USER_CODE_MAX_LENGTH];
	char		szUPN[EU_UPN_MAX_LENGTH];

	char		szUNZR[EU_UNZR_MAX_LENGTH];

	char		szCountry[EU_COUNTRY_MAX_LENGTH];
} EU_USER_INFO, *PEU_USER_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#ifdef OS_HPUX
#pragma pack(push, 4)
#else
#pragma pack(push, 1)
#endif
typedef struct
{
	int			nSN;
	char		szCommonName[EU_COMMON_NAME_MAX_LENGTH];
	char		szLocality[EU_LOCALITY_MAX_LENGTH];
	char		szState[EU_STATE_MAX_LENGTH];
	char		szOrganization[EU_ORGANIZATION_MAX_LENGTH];
	char		szOrgUnit[EU_ORG_UNIT_MAX_LENGTH];
	char		szTitle[EU_TITLE_MAX_LENGTH];
	char		szStreet[EU_STREET_MAX_LENGTH];
	char		szPhone[EU_PHONE_MAX_LENGTH];
	char		szSurname[EU_SURNAME_MAX_LENGTH];
	char		szGivenname[EU_GIVENNAME_MAX_LENGTH];
	char		szEMail[EU_EMAIL_MAX_LENGTH];
	char		szDNS[EU_ADDRESS_MAX_LENGTH];
	char		szEDRPOUCode[EU_EDRPOU_MAX_LENGTH];
	char		szDRFOCode[EU_DRFO_MAX_LENGTH];
	char		szNBUCode[EU_NBU_MAX_LENGTH];
	char		szSPFMCode[EU_SPFM_MAX_LENGTH];
	char		szInformation[EU_INFORMATION_MAX_LENGTH];
	char		szPassPhrase[EU_PASS_PHRASE_MAX_LENGTH];
	int			bPublishCertificate;
	int			nRAAdminSN;

	int			nVersion;
} EU_USER_PARAMS, *PEU_USER_PARAMS;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#pragma pack(push, 1)
typedef struct
{
	unsigned long		dwVersion;
	unsigned long long	dwlActiveSessions;
	unsigned long long	dwlGatedSessions;
	unsigned long long	dwlUnprotectedData;
	unsigned long long	dwlProtectedData;
} EU_SCC_STATISTIC, *PEU_SCC_STATISTIC;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#pragma pack(push, 1)
typedef struct
{
	unsigned long		dwVersion;
	int			bTimeAvail;
	int			bTimeStamp;
	SYSTEMTIME	Time;
	int			bSignTimeStampAvail;
	SYSTEMTIME	SignTimeStamp;
} EU_TIME_INFO, *PEU_TIME_INFO, **PPEU_TIME_INFO;
#pragma pack(pop)

//-----------------------------------------------------------------------------

#pragma pack(push, 1)
typedef struct
{
	unsigned long		dwVersion;
	char*		pszDeviceNameAlias;
} EU_KEY_MEDIA_DEVICE_INFO, *PEU_KEY_MEDIA_DEVICE_INFO, 
	**PPEU_KEY_MEDIA_DEVICE_INFO;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
	unsigned long		dwVersion;
	unsigned long		dwError;
	char*		pszHash;
	char*		pszSignature;
	unsigned long		dwStatus;
	char*		pszStatus;
} EU_SS_SIGN_HASH_RESULT, *PEU_SS_SIGN_HASH_RESULT, 
	**PPEU_SS_SIGN_HASH_RESULT;
#pragma pack(pop)

//=============================================================================

typedef unsigned long (*PEU_INITIALIZE)();
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUInitialize();
#endif //PC_STATIC_LIBS

typedef int (*PEU_IS_INITIALIZED)();
#ifdef PC_STATIC_LIBS
extern "C" int EUIsInitialized();
#endif //PC_STATIC_LIBS

typedef void (*PEU_FINALIZE)();
#ifdef PC_STATIC_LIBS
extern "C" void EUFinalize();
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef void (*PEU_SET_SETTINGS)();
#ifdef PC_STATIC_LIBS
extern "C" void EUSetSettings();
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef void (*PEU_SHOW_CERTIFICATES)();
#ifdef PC_STATIC_LIBS
extern "C" void EUShowCertificates();
#endif //PC_STATIC_LIBS

typedef void (*PEU_SHOW_CRLS)();
#ifdef PC_STATIC_LIBS
extern "C" void EUShowCRLs();
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_PRIVATE_KEY_MEDIA)(
	PEU_KEY_MEDIA	pKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetPrivateKeyMedia(
	PEU_KEY_MEDIA	pKeyMedia);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_READ_PRIVATE_KEY)(
	PEU_KEY_MEDIA	pKeyMedia,
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUReadPrivateKey(
	PEU_KEY_MEDIA	pKeyMedia,
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef int (*PEU_IS_PRIVATE_KEY_READED)();
#ifdef PC_STATIC_LIBS
extern "C" int EUIsPrivateKeyReaded();
#endif //PC_STATIC_LIBS

typedef void (*PEU_RESET_PRIVATE_KEY)();
#ifdef PC_STATIC_LIBS
extern "C" void EUResetPrivateKey();
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_CERT_OWNER_INFO)(
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCertOwnerInfo(
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef void (*PEU_SHOW_OWN_CERTIFICATE)();
#ifdef PC_STATIC_LIBS
extern "C" void EUShowOwnCertificate();
#endif //PC_STATIC_LIBS

typedef void (*PEU_SHOW_SIGN_INFO)(
	PEU_SIGN_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUShowSignInfo(
	PEU_SIGN_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_SIGN_INFO)(
	PEU_SIGN_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeSignInfo(
	PEU_SIGN_INFO	pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef void (*PEU_FREE_MEMORY)(
	unsigned char*			pbMemory);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeMemory(
	unsigned char*			pbMemory);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef char* (*PEU_GET_ERROR_DESC)(
	unsigned long			dwError);
#ifdef PC_STATIC_LIBS
extern "C" char* EUGetErrorDesc(
	unsigned long			dwError);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SIGN_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignData(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyData(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_CONTINUE)(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataContinue(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_END)(
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataEnd(
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_BEGIN)(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataBegin(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_CONTINUE)(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataContinue(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_END)(
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataEnd(
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_RESET_OPERATION)();
#ifdef PC_STATIC_LIBS
extern "C" void EUResetOperation();
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_FILE)(
	char*			pszFileName,
	char*			pszFileNameWithSign,
	int			bExternalSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignFile(
	char*			pszFileName,
	char*			pszFileNameWithSign,
	int			bExternalSign);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_FILE)(
	char*			pszFileNameWithSign,
	char*			pszFileName,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyFile(
	char*			pszFileNameWithSign,
	char*			pszFileName,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_INTERNAL)(
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataInternal(
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_INTERNAL)(
	char*			pszSignedData,
	unsigned char*			pbSignedData,
	unsigned long			dwSignedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataInternal(
	char*			pszSignedData,
	unsigned char*			pbSignedData,
	unsigned long			dwSignedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SELECT_CERTIFICATE_INFO)(
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSelectCertificateInfo(
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef void (*PEU_SET_UI_MODE)(
	int			bUIMode);
#ifdef PC_STATIC_LIBS
extern "C" void EUSetUIMode(
	int			bUIMode);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_HASH_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashData(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_HASH_DATA_CONTINUE)(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashDataContinue(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_HASH_DATA_END)(
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashDataEnd(
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_HASH_FILE)(
	char*			pszFileName,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashFile(
	char*			pszFileName,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_HASH)(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignHash(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_HASH)(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyHash(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENUM_KEY_MEDIA_TYPES)(
	unsigned long			dwTypeIndex,
	char*			pszTypeDescription);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumKeyMediaTypes(
	unsigned long			dwTypeIndex,
	char*			pszTypeDescription);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENUM_KEY_MEDIA_DEVICES)(
	unsigned long			dwTypeIndex,
	unsigned long			dwDeviceIndex,
	char*			pszDeviceDescription);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumKeyMediaDevices(
	unsigned long			dwTypeIndex,
	unsigned long			dwDeviceIndex,
	char*			pszDeviceDescription);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_FILE_STORE_SETTINGS)(
	char*			pszPath,
	int*			pbCheckCRLs,
	int*			pbAutoRefresh,
	int*			pbOwnCRLsOnly,
	int*			pbFullAndDeltaCRLs,
	int*			pbAutoDownloadCRLs,
	int*			pbSaveLoadedCerts,
	unsigned long*			pdwExpireTime);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileStoreSettings(
	char*			pszPath,
	int*			pbCheckCRLs,
	int*			pbAutoRefresh,
	int*			pbOwnCRLsOnly,
	int*			pbFullAndDeltaCRLs,
	int*			pbAutoDownloadCRLs,
	int*			pbSaveLoadedCerts,
	unsigned long*			pdwExpireTime);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_FILE_STORE_SETTINGS)(
	char*			pszPath,
	int			bCheckCRLs,
	int			bAutoRefresh,
	int			bOwnCRLsOnly,
	int			bFullAndDeltaCRLs,
	int			bAutoDownloadCRLs,
	int			bSaveLoadedCerts,
	unsigned long			dwExpireTime);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetFileStoreSettings(
	char*			pszPath,
	int			bCheckCRLs,
	int			bAutoRefresh,
	int			bOwnCRLsOnly,
	int			bFullAndDeltaCRLs,
	int			bAutoDownloadCRLs,
	int			bSaveLoadedCerts,
	unsigned long			dwExpireTime);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_PROXY_SETTINGS)(
	int*			pbUseProxy,
	int*			pbAnonymous,
	char*			pszAddress,
	char*			pszPort,
	char*			pszUser,
	char*			pszPassword,
	int*			pbSavePassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetProxySettings(
	int*			pbUseProxy,
	int*			pbAnonymous,
	char*			pszAddress,
	char*			pszPort,
	char*			pszUser,
	char*			pszPassword,
	int*			pbSavePassword);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_PROXY_SETTINGS)(
	int			bUseProxy,
	int			bAnonymous,
	char*			pszAddress,
	char*			pszPort,
	char*			pszUser,
	char*			pszPassword,
	int			bSavePassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetProxySettings(
	int			bUseProxy,
	int			bAnonymous,
	char*			pszAddress,
	char*			pszPort,
	char*			pszUser,
	char*			pszPassword,
	int			bSavePassword);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_OCSP_SETTINGS)(
	int*			pbUseOCSP,
	int*			pbBeforeStore,
	char*			pszAddress,
	char*			pszPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetOCSPSettings(
	int*			pbUseOCSP,
	int*			pbBeforeStore,
	char*			pszAddress,
	char*			pszPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_OCSP_SETTINGS)(
	int			bUseOCSP,
	int			bBeforeStore,
	char*			pszAddress,
	char*			pszPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetOCSPSettings(
	int			bUseOCSP,
	int			bBeforeStore,
	char*			pszAddress,
	char*			pszPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_TSP_SETTINGS)(
	int*			pbGetStamps,
	char*			pszAddress,
	char*			pszPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetTSPSettings(
	int*			pbGetStamps,
	char*			pszAddress,
	char*			pszPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_TSP_SETTINGS)(
	int			bGetStamps,
	char*			pszAddress,
	char*			pszPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetTSPSettings(
	int			bGetStamps,
	char*			pszAddress,
	char*			pszPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_LDAP_SETTINGS)(
	int*			pbUseLDAP,
	char*			pszAddress,
	char*			pszPort,
	int*			pbAnonymous,
	char*			pszUser,
	char*			pszPassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetLDAPSettings(
	int*			pbUseLDAP,
	char*			pszAddress,
	char*			pszPort,
	int*			pbAnonymous,
	char*			pszUser,
	char*			pszPassword);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_LDAP_SETTINGS)(
	int			bUseLDAP,
	char*			pszAddress,
	char*			pszPort,
	int			bAnonymous,
	char*			pszUser,
	char*			pszPassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetLDAPSettings(
	int			bUseLDAP,
	char*			pszAddress,
	char*			pszPort,
	int			bAnonymous,
	char*			pszUser,
	char*			pszPassword);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CMP_SETTINGS)(
	int*			pbUseCMP,
	char*			pszAddress,
	char*			pszPort,
	char*			pszCommonName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCMPSettings(
	int*			pbUseCMP,
	char*			pszAddress,
	char*			pszPort,
	char*			pszCommonName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_CMP_SETTINGS)(
	int			bUseCMP,
	char*			pszAddress,
	char*			pszPort,
	char*			pszCommonName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetCMPSettings(
	int			bUseCMP,
	char*			pszAddress,
	char*			pszPort,
	char*			pszCommonName);
#endif //PC_STATIC_LIBS

typedef int (*PEU_DOES_NEED_SET_SETTINGS)();
#ifdef PC_STATIC_LIBS
extern "C" int EUDoesNeedSetSettings();
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CERTIFICATES_COUNT)(
	unsigned long			dwSubjectType,
	unsigned long			dwSubjectSubType,
	unsigned long*			pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificatesCount(
	unsigned long			dwSubjectType,
	unsigned long			dwSubjectSubType,
	unsigned long*			pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENUM_CERTIFICATES)(
	unsigned long			dwSubjectType,
	unsigned long			dwSubjectSubType,
	unsigned long			dwIndex,
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumCertificates(
	unsigned long			dwSubjectType,
	unsigned long			dwSubjectSubType,
	unsigned long			dwIndex,
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CRLS_COUNT)(
	unsigned long*			pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCRLsCount(
	unsigned long*			pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENUM_CRLS)(
	unsigned long			dwIndex,
	PEU_CRL_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumCRLs(
	unsigned long			dwIndex,
	PEU_CRL_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_CRL_INFO)(
	PEU_CRL_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCRLInfo(
	PEU_CRL_INFO	pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CERTIFICATE_INFO)(
	char*			pszIssuer,
	char*			pszSerial,
	PEU_CERT_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateInfo(
	char*			pszIssuer,
	char*			pszSerial,
	PEU_CERT_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_CERTIFICATE_INFO)(
	PEU_CERT_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCertificateInfo(
	PEU_CERT_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CRL_DETAILED_INFO)(
	char*			pszIssuer,
	unsigned long			dwCRLNumber,
	PEU_CRL_DETAILED_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCRLDetailedInfo(
	char*			pszIssuer,
	unsigned long			dwCRLNumber,
	PEU_CRL_DETAILED_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_CRL_DETAILED_INFO)(
	PEU_CRL_DETAILED_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCRLDetailedInfo(
	PEU_CRL_DETAILED_INFO
					pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_PRIVATE_KEY_MEDIA_SETTINGS)(
	unsigned long*			pdwSourceType,
	int*			pbShowErrors,
	unsigned long*			pdwTypeIndex,
	unsigned long*			pdwDevIndex,
	char*			pszPassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetPrivateKeyMediaSettings(
	unsigned long*			pdwSourceType,
	int*			pbShowErrors,
	unsigned long*			pdwTypeIndex,
	unsigned long*			pdwDevIndex,
	char*			pszPassword);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_PRIVATE_KEY_MEDIA_SETTINGS)(
	unsigned long			dwSourceType,
	int			bShowErrors,
	unsigned long			dwTypeIndex,
	unsigned long			dwDevIndex,
	char*			pszPassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetPrivateKeyMediaSettings(
	unsigned long			dwSourceType,
	int			bShowErrors,
	unsigned long			dwTypeIndex,
	unsigned long			dwDevIndex,
	char*			pszPassword);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SELECT_CMP_SERVER)(
	char*			pszCommonName,
	char*			pszDNS);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSelectCMPServer(
	char*			pszCommonName,
	char*			pszDNS);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_RAW_SIGN_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawSignData(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RAW_VERIFY_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawVerifyData(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RAW_SIGN_HASH)(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawSignHash(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RAW_VERIFY_HASH)(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawVerifyHash(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RAW_SIGN_FILE)(
	char*			pszFileName,
	char*			pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawSignFile(
	char*			pszFileName,
	char*			pszFileNameWithSign);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RAW_VERIFY_FILE)(
	char*			pszFileNameWithSign,
	char*			pszFileName,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawVerifyFile(
	char*			pszFileNameWithSign,
	char*			pszFileName,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_BASE64_ENCODE)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszData);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUBASE64Encode(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszData);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_BASE64_DECODE)(
	char*			pszData,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUBASE64Decode(
	char*			pszData,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_DATA)(
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopData(
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEVELOP_DATA)(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevelopData(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_SHOW_SENDER_INFO)(
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUShowSenderInfo(
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_SENDER_INFO)(
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeSenderInfo(
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_PARSE_CERTIFICATE)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	PEU_CERT_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUParseCertificate(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	PEU_CERT_INFO	pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_READ_PRIVATE_KEY_BINARY)(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUReadPrivateKeyBinary(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_READ_PRIVATE_KEY_FILE)(
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUReadPrivateKeyFile(
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef void (*PEU_SESSION_DESTROY)(
	void*			pvSession);
#ifdef PC_STATIC_LIBS
extern "C" void EUSessionDestroy(
	void*			pvSession);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CLIENT_SESSION_CREATE_STEP1)(
	unsigned long			dwExpireTime,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUClientSessionCreateStep1(
	unsigned long			dwExpireTime,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SERVER_SESSION_CREATE_STEP1)(
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUServerSessionCreateStep1(
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CLIENT_SESSION_CREATE_STEP2)(
	void*			pvClientSession,
	unsigned char*			pbServerData,
	unsigned long			dwServerDataLength,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUClientSessionCreateStep2(
	void*			pvClientSession,
	unsigned char*			pbServerData,
	unsigned long			dwServerDataLength,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SERVER_SESSION_CREATE_STEP2)(
	void*			pvServerSession,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUServerSessionCreateStep2(
	void*			pvServerSession,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength);
#endif //PC_STATIC_LIBS

typedef int (*PEU_SESSION_IS_INITIALIZED)(
	void*			pvSession);
#ifdef PC_STATIC_LIBS
extern "C" int EUSessionIsInitialized(
	void*			pvSession);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SESSION_SAVE)(
	void*			pvSession,
	unsigned char*			*ppbSessionData,
	unsigned long*			pdwSessionDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionSave(
	void*			pvSession,
	unsigned char*			*ppbSessionData,
	unsigned long*			pdwSessionDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SESSION_LOAD)(
	unsigned char*			pbSessionData,
	unsigned long			dwSessionDataLength,
	void*			*ppvSession);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionLoad(
	unsigned char*			pbSessionData,
	unsigned long			dwSessionDataLength,
	void*			*ppvSession);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SESSION_CHECK_CERTIFICATES)(
	void*			pvSession);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionCheckCertificates(
	void*			pvSession);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SESSION_ENCRYPT)(
	void*			pvSession,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			*ppbEncryptedData,
	unsigned long*			pdwEncryptedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionEncrypt(
	void*			pvSession,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			*ppbEncryptedData,
	unsigned long*			pdwEncryptedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SESSION_ENCRYPT_CONTINUE)(
	void*			pvSession,
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionEncryptContinue(
	void*			pvSession,
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SESSION_DECRYPT)(
	void*			pvSession,
	unsigned char*			pbEncryptedData,
	unsigned long			dwEncryptedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionDecrypt(
	void*			pvSession,
	unsigned char*			pbEncryptedData,
	unsigned long			dwEncryptedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SESSION_DECRYPT_CONTINUE)(
	void*			pvSession,
	unsigned char*			pbEncryptedData,
	unsigned long			dwEncryptedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionDecryptContinue(
	void*			pvSession,
	unsigned char*			pbEncryptedData,
	unsigned long			dwEncryptedDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef int (*PEU_IS_SIGNED_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" int EUIsSignedData(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef int (*PEU_IS_ENVELOPED_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" int EUIsEnvelopedData(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SESSION_GET_PEER_CERTIFICATE_INFO)(
	void*			pvSession,
	PEU_CERT_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSessionGetPeerCertificateInfo(
	void*			pvSession,
	PEU_CERT_INFO	pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SAVE_CERTIFICATE)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSaveCertificate(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_REFRESH_FILE_STORE)(
	int			bReload);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURefreshFileStore(
	int			bReload);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_MODE_SETTINGS)(
	int*			pbOfflineMode);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetModeSettings(
	int*			pbOfflineMode);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_MODE_SETTINGS)(
	int			bOfflineMode);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetModeSettings(
	int			bOfflineMode);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_CHECK_CERTIFICATE)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCheckCertificate(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_FILE)(
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFile(
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEVELOP_FILE)(
	char*			pszEnvelopedFileName,
	char*			pszFileName,
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevelopFile(
	char*			pszEnvelopedFileName,
	char*			pszFileName,
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef int (*PEU_IS_SIGNED_FILE)(
	char*			pszFileName);
#ifdef PC_STATIC_LIBS
extern "C" int EUIsSignedFile(
	char*			pszFileName);
#endif //PC_STATIC_LIBS

typedef int (*PEU_IS_ENVELOPED_FILE)(
	char*			pszFileName);
#ifdef PC_STATIC_LIBS
extern "C" int EUIsEnvelopedFile(
	char*			pszFileName);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CERTIFICATE)(
	char*			pszIssuer,
	char*			pszSerial,
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificate(
	char*			pszIssuer,
	char*			pszSerial,
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_OWN_CERTIFICATE)(
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetOwnCertificate(
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENUM_OWN_CERTIFICATES)(
	unsigned long			dwIndex,
	PPEU_CERT_INFO_EX 
					ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumOwnCertificates(
	unsigned long			dwIndex,
	PPEU_CERT_INFO_EX 
					ppInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CERTIFICATE_INFO_EX)(
	char*			pszIssuer,
	char*			pszSerial,
	PPEU_CERT_INFO_EX
					ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateInfoEx(
	char*			pszIssuer,
	char*			pszSerial,
	PPEU_CERT_INFO_EX
					ppInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_CERTIFICATE_INFO_EX)(
	PEU_CERT_INFO_EX
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCertificateInfoEx(
	PEU_CERT_INFO_EX
					pInfo);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_RECEIVERS_CERTIFICATES)(
	PPEU_CERTIFICATES
					ppCertificates);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetReceiversCertificates(
	PPEU_CERTIFICATES
					ppCertificates);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_RECEIVERS_CERTIFICATES)(
	PEU_CERTIFICATES
					pCertificates);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeReceiversCertificates(
	PEU_CERTIFICATES
					pCertificates);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GENERATE_PRIVATE_KEY)(
	PEU_KEY_MEDIA	pKeyMedia,
	unsigned long			dwUAKeysType,
	unsigned long			dwUADSKeysSpec,
	unsigned long			dwUAKEPKeysSpec,
	char*			pszUAParamsPath,
	unsigned long			dwInternationalKeysType,
	unsigned long			dwInternationalKeysSpec,
	char*			pszInternationalParamsPath,
	unsigned char*			*ppbPrivKey,
	unsigned long*			pdwPrivKey,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo,
	unsigned char*			*ppbUARequest,
	unsigned long*			pdwUARequest,
	char*			pszUAReqFileName,
	unsigned char*			*ppbUAKEPRequest,
	unsigned long*			pdwUAKEPRequest,
	char*			pszUAKEPReqFileName,
	unsigned char*			*ppbInternationalRequest,
	unsigned long*			pdwInternationalRequest,
	char*			pszInternationalReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGeneratePrivateKey(
	PEU_KEY_MEDIA	pKeyMedia,
	unsigned long			dwUAKeysType,
	unsigned long			dwUADSKeysSpec,
	unsigned long			dwUAKEPKeysSpec,
	char*			pszUAParamsPath,
	unsigned long			dwInternationalKeysType,
	unsigned long			dwInternationalKeysSpec,
	char*			pszInternationalParamsPath,
	unsigned char*			*ppbPrivKey,
	unsigned long*			pdwPrivKey,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo,
	unsigned char*			*ppbUARequest,
	unsigned long*			pdwUARequest,
	char*			pszUAReqFileName,
	unsigned char*			*ppbUAKEPRequest,
	unsigned long*			pdwUAKEPRequest,
	char*			pszUAKEPReqFileName,
	unsigned char*			*ppbInternationalRequest,
	unsigned long*			pdwInternationalRequest,
	char*			pszInternationalReqFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CHANGE_PRIVATE_KEY_PASSWORD)(
	PEU_KEY_MEDIA	pKeyMedia,
	char*			pszNewPassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUChangePrivateKeyPassword(
	PEU_KEY_MEDIA	pKeyMedia,
	char*			pszNewPassword);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_BACKUP_PRIVATE_KEY)(
	PEU_KEY_MEDIA	pSourceKeyMedia,
	PEU_KEY_MEDIA	pTargetKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUBackupPrivateKey(
	PEU_KEY_MEDIA	pSourceKeyMedia,
	PEU_KEY_MEDIA	pTargetKeyMedia);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DESTROY_PRIVATE_KEY)(
	PEU_KEY_MEDIA	pKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDestroyPrivateKey(
	PEU_KEY_MEDIA	pKeyMedia);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_IS_HARDWARE_KEY_MEDIA)(
	PEU_KEY_MEDIA	pKeyMedia,
	int*			pbHardware);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsHardwareKeyMedia(
	PEU_KEY_MEDIA	pKeyMedia,
	int*			pbHardware);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_IS_PRIVATE_KEY_EXISTS)(
	PEU_KEY_MEDIA	pKeyMedia,
	int*			pbExists);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsPrivateKeyExists(
	PEU_KEY_MEDIA	pKeyMedia,
	int*			pbExists);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CR_INFO)(
	unsigned char*			pbRequest,
	unsigned long			dwRequest,
	PEU_CR_INFO		*ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCRInfo(
	unsigned char*			pbRequest,
	unsigned long			dwRequest,
	PEU_CR_INFO		*ppInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_CR_INFO)(
	PEU_CR_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCRInfo(
	PEU_CR_INFO		pInfo);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SAVE_CERTIFICATES)(
	unsigned char*			pbCertificates,
	unsigned long			dwCertificatesLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSaveCertificates(
	unsigned char*			pbCertificates,
	unsigned long			dwCertificatesLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SAVE_CRL)(
	int			bFullCRL,
	unsigned char*			pbCRL,
	unsigned long			dwCRLLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSaveCRL(
	int			bFullCRL,
	unsigned char*			pbCRL,
	unsigned long			dwCRLLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CERTIFICATE_BY_EMAIL)(
	char*			pszEMail,
	unsigned long			dwCertKeyType,
	unsigned long			dwKeyUsage,
	PSYSTEMTIME		pOnTime,
	char*			pszIssuer,
	char*			pszSerial);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateByEMail(
	char*			pszEMail,
	unsigned long			dwCertKeyType,
	unsigned long			dwKeyUsage,
	PSYSTEMTIME		pOnTime,
	char*			pszIssuer,
	char*			pszSerial);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CERTIFICATE_BY_NBU_CODE)(
	char*			pszNBUCode,
	unsigned long			dwCertKeyType,
	unsigned long			dwKeyUsage,
	PSYSTEMTIME		pOnTime,
	char*			pszIssuer,
	char*			pszSerial);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateByNBUCode(
	char*			pszNBUCode,
	unsigned long			dwCertKeyType,
	unsigned long			dwKeyUsage,
	PSYSTEMTIME		pOnTime,
	char*			pszIssuer,
	char*			pszSerial);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_APPEND_SIGN)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendSign(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_APPEND_SIGN_INTERNAL)(
	int			bAppendCert,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendSignInternal(
	int			bAppendCert,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_SPECIFIC)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataSpecific(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_INTERNAL_SPECIFIC)(
	unsigned long			dwSignIndex,
	char*			pszSignedData,
	unsigned char*			pbSignedData,
	unsigned long			dwSignedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataInternalSpecific(
	unsigned long			dwSignIndex,
	char*			pszSignedData,
	unsigned char*			pbSignedData,
	unsigned long			dwSignedDataLength,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_APPEND_SIGN_BEGIN)(
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendSignBegin(
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_SPECIFIC_BEGIN)(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataSpecificBegin(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_APPEND_SIGN_FILE)(
	char*			pszFileName,
	char*			pszFileNameWithPreviousSign,
	char*			pszFileNameWithSign,
	int			bExternalSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendSignFile(
	char*			pszFileName,
	char*			pszFileNameWithPreviousSign,
	char*			pszFileNameWithSign,
	int			bExternalSign);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_FILE_SPECIFIC)(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	char*			pszFileName,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyFileSpecific(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	char*			pszFileName,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_APPEND_SIGN_HASH)(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendSignHash(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_HASH_SPECIFIC)(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyHashSpecific(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_SIGNS_COUNT)(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	unsigned long*			pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetSignsCount(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	unsigned long*			pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_SIGNER_INFO)(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetSignerInfo(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_FILE_SIGNS_COUNT)(
	char*			pszFileNameWithSign,
	unsigned long*			pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileSignsCount(
	char*			pszFileNameWithSign,
	unsigned long*			pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_FILE_SIGNER_INFO)(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileSignerInfo(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_IS_ALREADY_SIGNED)(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	int*			pbIsAlreadySigned);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsAlreadySigned(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	int*			pbIsAlreadySigned);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_IS_FILE_ALREADY_SIGNED)(
	char*			pszFileNameWithSign,
	int*			pbIsAlreadySigned);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsFileAlreadySigned(
	char*			pszFileNameWithSign,
	int*			pbIsAlreadySigned);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_HASH_DATA_WITH_PARAMS)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashDataWithParams(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_HASH_DATA_BEGIN_WITH_PARAMS)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashDataBeginWithParams(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_HASH_FILE_WITH_PARAMS)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			pszFileName,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashFileWithParams(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			pszFileName,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_DATA_EX)(
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataEx(
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SET_SETTINGS_FILE_PATH)(
	char*			pszSettingsFilePath);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetSettingsFilePath(
	char*			pszSettingsFilePath);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SET_KEY_MEDIA_PASSWORD)(
	PEU_KEY_MEDIA		pKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetKeyMediaPassword(
	PEU_KEY_MEDIA		pKeyMedia);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GENERATE_PRIVATE_KEY_EX)(
	PEU_KEY_MEDIA		pKeyMedia,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbPrivKey,
	unsigned long*				pdwPrivKey,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfo,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGeneratePrivateKeyEx(
	PEU_KEY_MEDIA		pKeyMedia,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbPrivKey,
	unsigned long*				pdwPrivKey,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfo,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef char* (*PEU_GET_ERROR_LANG_DESC)(
	unsigned long				dwError,
	unsigned long				dwLang);
#ifdef PC_STATIC_LIBS
extern "C" char* EUGetErrorLangDesc(
	unsigned long				dwError,
	unsigned long				dwLang);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_FILE_EX)(
	char*				pszRecipientCertIssuers,
	char*				pszRecipientCertSerials,
	int				bSignData,
	char*				pszFileName,
	char*				pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileEx(
	char*				pszRecipientCertIssuers,
	char*				pszRecipientCertSerials,
	int				bSignData,
	char*				pszFileName,
	char*				pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_IS_CERTIFICATES)(
	unsigned char*				pbCertificates,
	unsigned long				dwCertificatesLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsCertificates(
	unsigned char*				pbCertificates,
	unsigned long				dwCertificatesLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_IS_CERTIFICATES_FILE)(
	char*				pszFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsCertificatesFile(
	char*				pszFileName);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENUM_CERTIFICATES_BY_O_CODE)(
	char*				pszOCode,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PSYSTEMTIME			pOnTime,
	unsigned long				dwIndex,
	char*				pszIssuer,
	char*				pszSerial);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumCertificatesByOCode(
	char*				pszOCode,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PSYSTEMTIME			pOnTime,
	unsigned long				dwIndex,
	char*				pszIssuer,
	char*				pszSerial);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CERTIFICATES_BY_O_CODE)(
	char*				pszOCode,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PSYSTEMTIME			pOnTime,
	unsigned long*				pdwIssuersCount,
	unsigned long*				pdwSerialsCount,
	char*				pszIssuers,
	char*				pszSerials);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificatesByOCode(
	char*				pszOCode,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PSYSTEMTIME			pOnTime,
	unsigned long*				pdwIssuersCount,
	unsigned long*				pdwSerialsCount,
	char*				pszIssuers,
	char*				pszSerials);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SET_PRIVATE_KEY_MEDIA_SETTINGS_PROTECTED)(
	unsigned long			dwSourceType,
	int			bShowErrors,
	unsigned long			dwTypeIndex,
	unsigned long			dwDevIndex,
	char*			pszPassword,
	int			bRuntime);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetPrivateKeyMediaSettingsProtected(
	unsigned long			dwSourceType,
	int			bShowErrors,
	unsigned long			dwTypeIndex,
	unsigned long			dwDevIndex,
	char*			pszPassword,
	int			bRuntime);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataToRecipients(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_FILE_TO_RECIPIENTS)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileToRecipients(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_DATA_EX_WITH_DYNAMIC_KEY)(
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataExWithDynamicKey(
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_DYNAMIC_KEY)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataToRecipientsWithDynamicKey(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_FILE_EX_WITH_DYNAMIC_KEY)(
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	int			bAppendCert,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileExWithDynamicKey(
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	int			bAppendCert,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_FILE_TO_RECIPIENTS_WITH_DYNAMIC_KEY)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	int			bAppendCert,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileToRecipientsWithDynamicKey(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	int			bAppendCert,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SAVE_PRIVATE_KEY)(
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	PEU_KEY_MEDIA		pTargetKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSavePrivateKey(
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	PEU_KEY_MEDIA		pTargetKeyMedia);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_LOAD_PRIVATE_KEY)(
	PEU_KEY_MEDIA		pSourceKeyMedia,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EULoadPrivateKey(
	PEU_KEY_MEDIA		pSourceKeyMedia,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CHANGE_SOFTWARE_PRIVATE_KEY_PASSWORD)(
	unsigned char*				pbPrivateKeySource,
	unsigned long				dwPrivateKeySourceLength,
	char*				pszOldPassword,
	char*				pszNewPassword,
	unsigned char*				*ppbPrivateKeyTarget,
	unsigned long*				pdwPrivateKeyTargetLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUChangeSoftwarePrivateKeyPassword(
	unsigned char*				pbPrivateKeySource,
	unsigned long				dwPrivateKeySourceLength,
	char*				pszOldPassword,
	char*				pszNewPassword,
	unsigned char*				*ppbPrivateKeyTarget,
	unsigned long*				pdwPrivateKeyTargetLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_HASH_DATA_BEGIN_WITH_PARAMS_CTX)(
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength, 
	void*				*ppvContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashDataBeginWithParamsCtx(
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength, 
	void*				*ppvContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_HASH_DATA_CONTINUE_CTX)(
	void*				*ppvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashDataContinueCtx(
	void*				*ppvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_HASH_DATA_END_CTX)(
	void*				pvContext,
	char*				*ppszHash,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUHashDataEndCtx(
	void*				pvContext,
	char*				*ppszHash,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CERTIFICATE_BY_KEY_INFO)(
	unsigned long				dwTypeIndex,
	unsigned long				dwDevIndex,
	unsigned char*				pbPrivKeyInfo,
	unsigned long				dwPrivKeyInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateByKeyInfo(
	unsigned long				dwTypeIndex,
	unsigned long				dwDevIndex,
	unsigned char*				pbPrivKeyInfo,
	unsigned long				dwPrivKeyInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SAVE_PRIVATE_KEY_EX)(
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	unsigned char*				pbPrivateKeyInfo,
	unsigned long				dwPrivateKeyInfoLength,
	PEU_KEY_MEDIA		pTargetKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSavePrivateKeyEx(
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	unsigned char*				pbPrivateKeyInfo,
	unsigned long				dwPrivateKeyInfoLength,
	PEU_KEY_MEDIA		pTargetKeyMedia);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_LOAD_PRIVATE_KEY_EX)(
	PEU_KEY_MEDIA		pSourceKeyMedia,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength,
	unsigned char*				*ppbPrivateKeyInfo,
	unsigned long*				pdwPrivateKeyInfoLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EULoadPrivateKeyEx(
	PEU_KEY_MEDIA		pSourceKeyMedia,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength,
	unsigned char*				*ppbPrivateKeyInfo,
	unsigned long*				pdwPrivateKeyInfoLength);
#endif //PC_STATIC_LIBS
//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_CREATE_EMPTY_SIGN)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateEmptySign(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CREATE_SIGNER)(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				*ppszSigner,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateSigner(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				*ppszSigner,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_APPEND_SIGNER)(
	char*				pszSigner,
	unsigned char*				pbSigner,
	unsigned long				dwSignerLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszPreviousSign,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendSigner(
	char*				pszSigner,
	unsigned char*				pbSigner,
	unsigned long				dwSignerLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszPreviousSign,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SET_RUNTIME_PARAMETER)(
	char*				pszParameterName,
	void*				pvParameterValue,
	unsigned long				dwParameterValueLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetRuntimeParameter(
	char*				pszParameterName,
	void*				pvParameterValue,
	unsigned long				dwParameterValueLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS_EX)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	unsigned long			dwRecipientAppendType,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataToRecipientsEx(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	unsigned long			dwRecipientAppendType,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_FILE_TO_RECIPIENTS_EX)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	unsigned long			dwRecipientAppendType,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileToRecipientsEx(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	unsigned long			dwRecipientAppendType,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_O_CODE)(
	char*			pszRecipientsOCode,
	unsigned long			dwRecipientAppendType,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataToRecipientsWithOCode(
	char*			pszRecipientsOCode,
	unsigned long			dwRecipientAppendType,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SIGN_DATA_CONTINUE_CTX)(
	void*				*ppvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataContinueCtx(
	void*				*ppvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_END_CTX)(
	void*				pvContext,
	int				bAppendCert,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataEndCtx(
	void*				pvContext,
	int				bAppendCert,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_BEGIN_CTX)(
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	void*				*ppvContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataBeginCtx(
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	void*				*ppvContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_CONTINUE_CTX)(
	void*				pvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataContinueCtx(
	void*				pvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_END_CTX)(
	void*				pvContext,
	PEU_SIGN_INFO		pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataEndCtx(
	void*				pvContext,
	PEU_SIGN_INFO		pSignInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_RESET_OPERATION_CTX)(
	void*				pvContext);
#ifdef PC_STATIC_LIBS
extern "C" void EUResetOperationCtx(
	void*				pvContext);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_SIGN_DATA_RSA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bAppendCert,
	int			bExternalSign,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataRSA(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bAppendCert,
	int			bExternalSign,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_RSA_CONTINUE)(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataRSAContinue(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_RSA_END)(
	int			bAppendCert,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataRSAEnd(
	int			bAppendCert,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_FILE_RSA)(
	char*			pszFileName,
	char*			pszFileNameWithSign,
	int			bExternalSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignFileRSA(
	char*			pszFileName,
	char*			pszFileNameWithSign,
	int			bExternalSign);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_RSA_CONTINUE_CTX)(
	void*			*ppvContext,
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataRSAContinueCtx(
	void*			*ppvContext,
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SIGN_DATA_RSA_END_CTX)(
	void*			pvContext,
	int			bAppendCert,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataRSAEndCtx(
	void*			pvContext,
	int			bAppendCert,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_DOWNLOAD_FILE_VIA_HTTP)(
	char*			pszURL,
	char*			pszFileName,
	unsigned char*			*ppbFile,
	unsigned long*			pdwFileLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDownloadFileViaHTTP(
	char*			pszURL,
	char*			pszFileName,
	unsigned char*			*ppbFile,
	unsigned long*			pdwFileLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_PARSE_CRL)(
	unsigned char*			pbCRL,
	unsigned long			dwCRLLength,
	PEU_CRL_DETAILED_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUParseCRL(
	unsigned char*			pbCRL,
	unsigned long			dwCRLLength,
	PEU_CRL_DETAILED_INFO
					pInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_IS_OLD_FORMAT_SIGN)(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	int*			pbOldFormatSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsOldFormatSign(
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	int*			pbOldFormatSign);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_IS_OLD_FORMAT_SIGN_FILE)(
	char*		pszFileNameWithSign,
	int*		pbOldFormatSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsOldFormatSignFile(
	char*		pszFileNameWithSign,
	int*		pbOldFormatSign);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_PRIVATE_KEY_MEDIA_EX)(
	char*			pszCaption,
	PEU_KEY_MEDIA	pKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetPrivateKeyMediaEx(
	char*			pszCaption,
	PEU_KEY_MEDIA	pKeyMedia);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_KEY_INFO)(
	PEU_KEY_MEDIA	pKeyMedia,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetKeyInfo(
	PEU_KEY_MEDIA	pKeyMedia,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_KEY_INFO_BINARY)(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetKeyInfoBinary(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_KEY_INFO_FILE)(
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetKeyInfoFile(
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CERTIFICATES_BY_KEY_INFO)(
	unsigned char*			pbPrivKeyInfo,
	unsigned long			dwPrivKeyInfo,
	char*			pszCMPServers,
	char*			pszCMPServersPorts,
	unsigned char*			*pbCertificates,
	unsigned long*			pdwCertificates);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificatesByKeyInfo(
	unsigned char*			pbPrivKeyInfo,
	unsigned long			dwPrivKeyInfo,
	char*			pszCMPServers,
	char*			pszCMPServersPorts,
	unsigned char*			*pbCertificates,
	unsigned long*			pdwCertificates);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_ENVELOP_APPEND_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopAppendData(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_APPEND_FILE)(
	char*			pszFileName,
	char*			pszPreviousEnvelopedFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopAppendFile(
	char*			pszFileName,
	char*			pszPreviousEnvelopedFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_APPEND_DATA_EX)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopAppendDataEx(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_APPEND_FILE_EX)(
	char*			pszFileName,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszPreviousEnvelopedFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopAppendFileEx(
	char*			pszFileName,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszPreviousEnvelopedFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_STORAGE_PARAMETER)(
	int			bProtected,
	char*			pszName,
	char*			pszValue);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetStorageParameter(
	int			bProtected,
	char*			pszName,
	char*			pszValue);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_STORAGE_PARAMETER)(
	int			bProtected,
	char*			pszName,
	char*			pszValue);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetStorageParameter(
	int			bProtected,
	char*			pszName,
	char*			pszValue);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_DEVELOP_DATA_EX)(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevelopDataEx(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEVELOP_FILE_EX)(
	char*			pszEnvelopedFileName,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszFileName,
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevelopFileEx(
	char*			pszEnvelopedFileName,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszFileName,
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_OCSP_ACCESS_INFO_MODE_SETTINGS)(
	int*			pbEnabled);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetOCSPAccessInfoModeSettings(
	int*			pbEnabled);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_OCSP_ACCESS_INFO_MODE_SETTINGS)(
	int			bEnabled);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetOCSPAccessInfoModeSettings(
	int			bEnabled);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENUM_OCSP_ACCESS_INFO_SETTINGS)(
	unsigned long		dwIndex,
	char*		pszIssuerCN,
	char*		pszAddress,
	char*		pszPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumOCSPAccessInfoSettings(
	unsigned long		dwIndex,
	char*		pszIssuerCN,
	char*		pszAddress,
	char*		pszPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_OCSP_ACCESS_INFO_SETTINGS)(
	char*		pszIssuerCN,
	char*		pszAddress,
	char*		pszPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetOCSPAccessInfoSettings(
	char*		pszIssuerCN,
	char*		pszAddress,
	char*		pszPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_OCSP_ACCESS_INFO_SETTINGS)(
	char*		pszIssuerCN,
	char*		pszAddress,
	char*		pszPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetOCSPAccessInfoSettings(
	char*		pszIssuerCN,
	char*		pszAddress,
	char*		pszPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DELETE_OCSP_ACCESS_INFO_SETTINGS)(
	char*		pszIssuerCN);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDeleteOCSPAccessInfoSettings(
	char*		pszIssuerCN);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CHECK_CERTIFICATE_BY_ISSUER_AND_SERIAL)(
	char*			pszIssuer,
	char*			pszSerial,
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCheckCertificateByIssuerAndSerial(
	char*			pszIssuer,
	char*			pszSerial,
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_PARSE_CERTIFICATE_EX)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	PPEU_CERT_INFO_EX	
					ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUParseCertificateEx(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	PPEU_CERT_INFO_EX	
					ppInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CHECK_CERTIFICATE_BY_ISSUER_AND_SERIAL_EX)(
	char*			pszIssuer,
	char*			pszSerial,
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength,
	unsigned long*			pdwOCSPAvailability);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCheckCertificateByIssuerAndSerialEx(
	char*			pszIssuer,
	char*			pszSerial,
	char*			*ppszCertificate,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertificateLength,
	unsigned long*			pdwOCSPAvailability);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CLIENT_DYNAMIC_KEY_SESSION_CREATE)(
	unsigned long			dwExpireTime,
	char*			pszServerCertIssuer,
	char*			pszServerCertSerial,
	unsigned char*			pbServerCert,
	unsigned long			dwServerCertLength,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUClientDynamicKeySessionCreate(
	unsigned long			dwExpireTime,
	char*			pszServerCertIssuer,
	char*			pszServerCertSerial,
	unsigned char*			pbServerCert,
	unsigned long			dwServerCertLength,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SERVER_DYNAMIC_KEY_SESSION_CREATE)(
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUServerDynamicKeySessionCreate(
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_SENDER_INFO)(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbRecipientCert,
	unsigned long			dwRecipientCertLength,
	int*			pbDynamicKey,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetSenderInfo(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbRecipientCert,
	unsigned long			dwRecipientCertLength,
	int*			pbDynamicKey,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_FILE_SENDER_INFO)(
	char*			pszEnvelopedFileName,
	unsigned char*			pbRecipientCert,
	unsigned long			dwRecipientCertLength,
	int*			pbDynamicKey,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileSenderInfo(
	char*			pszEnvelopedFileName,
	unsigned char*			pbRecipientCert,
	unsigned long			dwRecipientCertLength,
	int*			pbDynamicKey,
	PPEU_CERT_INFO_EX
					ppInfo,
	unsigned char*			*ppbCertificate,
	unsigned long*			pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_SC_CLIENT_IS_RUNNING)(
	int*			pbRunning);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSCClientIsRunning(
	int*			pbRunning);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SC_CLIENT_START)();
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSCClientStart();
#endif //PC_STATIC_LIBS

typedef void (*PEU_SC_CLIENT_STOP)();
#ifdef PC_STATIC_LIBS
extern "C" void EUSCClientStop();
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SC_CLIENT_ADD_GATE)(
	char*			pszGateName,
	unsigned short			wConnectPort,
	char*			pszGatewayAddress,
	unsigned short			wGatewayPort,
	char*			pszExternalInterface,
	char*			pszExternalRouterIPAddress);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSCClientAddGate(
	char*			pszGateName,
	unsigned short			wConnectPort,
	char*			pszGatewayAddress,
	unsigned short			wGatewayPort,
	char*			pszExternalInterface,
	char*			pszExternalRouterIPAddress);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SC_CLIENT_REMOVE_GATE)(
	unsigned short			wConnectPort);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSCClientRemoveGate(
	unsigned short			wConnectPort);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SC_CLIENT_GET_STATISTIC)(
	PEU_SCC_STATISTIC	*ppStatistic);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSCClientGetStatistic(
	PEU_SCC_STATISTIC	*ppStatistic);
#endif //PC_STATIC_LIBS

typedef void (*PEU_SC_CLIENT_FREE_STATISTIC)(
	PEU_SCC_STATISTIC	pStatistic);
#ifdef PC_STATIC_LIBS
extern "C" void EUSCClientFreeStatistic(
	PEU_SCC_STATISTIC	pStatistic);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_RECIPIENTS_COUNT)(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned long*			pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetRecipientsCount(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned long*			pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_FILE_RECIPIENTS_COUNT)(
	char*			pszEnvelopedFileName,
	unsigned long*			pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileRecipientsCount(
	char*			pszEnvelopedFileName,
	unsigned long*			pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_RECIPIENT_INFO)(
	unsigned long			dwRecipientIndex,
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned long*			pdwRecipientInfoType,
	char*			*ppszRecipientIssuer,
	char*			*ppszRecipientSerial,
	char*			*ppszRecipientPublicKeyID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetRecipientInfo(
	unsigned long			dwRecipientIndex,
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned long*			pdwRecipientInfoType,
	char*			*ppszRecipientIssuer,
	char*			*ppszRecipientSerial,
	char*			*ppszRecipientPublicKeyID);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_FILE_RECIPIENT_INFO)(
	unsigned long			dwRecipientIndex,
	char*			pszEnvelopedFileName,
	unsigned long*			pdwRecipientInfoType,
	char*			*ppszRecipientIssuer,
	char*			*ppszRecipientSerial,
	char*			*ppszRecipientPublicKeyID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileRecipientInfo(
	unsigned long			dwRecipientIndex,
	char*			pszEnvelopedFileName,
	unsigned long*			pdwRecipientInfoType,
	char*			*ppszRecipientIssuer,
	char*			*ppszRecipientSerial,
	char*			*ppszRecipientPublicKeyID);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_CREATE)(
	void*			*ppvContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxCreate(
	void*			*ppvContext);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE)(
	void*			pvContext);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFree(
	void*			pvContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_SET_PARAMETER)(
	void*			pvContext,
	char*			pszParameterName,
	void*			pvParameterValue,
	unsigned long			dwParameterValueLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxSetParameter(
	void*			pvContext,
	char*			pszParameterName,
	void*			pvParameterValue,
	unsigned long			dwParameterValueLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_READ_PRIVATE_KEY)(
	void*			pvContext,
	PEU_KEY_MEDIA	pKeyMedia,
	void*			*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxReadPrivateKey(
	void*			pvContext,
	PEU_KEY_MEDIA	pKeyMedia,
	void*			*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_READ_PRIVATE_KEY_BINARY)(
	void*			pvContext,
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	void*			*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxReadPrivateKeyBinary(
	void*			pvContext,
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	void*			*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_READ_PRIVATE_KEY_FILE)(
	void*			pvContext,
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	void*			*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxReadPrivateKeyFile(
	void*			pvContext,
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	void*			*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE_PRIVATE_KEY)(
	void*			pvPrivateKeyContext);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreePrivateKey(
	void*			pvPrivateKeyContext);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_DEVELOP_DATA)(
	void*			pvPrivateKeyContext,
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxDevelopData(
	void*			pvPrivateKeyContext,
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_DEVELOP_FILE)(
	void*			pvPrivateKeyContext,
	char*			pszEnvelopedFileName,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszFileName,
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxDevelopFile(
	void*			pvPrivateKeyContext,
	char*			pszEnvelopedFileName,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertSize,
	char*			pszFileName,
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef void (*PEU_CTX_FREE_MEMORY)(
	void*				pvContext,
	unsigned char*				pbMemory);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeMemory(
	void*				pvContext,
	unsigned char*				pbMemory);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE_CERT_OWNER_INFO)(
	void*				pvContext,
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeCertOwnerInfo(
	void*				pvContext,
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE_CERTIFICATE_INFO_EX)(
	void*				pvContext,
	PEU_CERT_INFO_EX	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeCertificateInfoEx(
	void*				pvContext,
	PEU_CERT_INFO_EX	pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE_SIGN_INFO)(
	void*				pvContext,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeSignInfo(
	void*				pvContext,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE_SENDER_INFO)(
	void*				pvContext,
	PEU_ENVELOP_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeSenderInfo(
	void*				pvContext,
	PEU_ENVELOP_INFO	pInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_GET_OWN_CERTIFICATE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetOwnCertificate(
	void*				pvPrivateKeyContext,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ENUM_OWN_CERTIFICATES)(
	void*				pvPrivateKeyContext,
	unsigned long				dwIndex,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnumOwnCertificates(
	void*				pvPrivateKeyContext,
	unsigned long				dwIndex,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_HASH_DATA)(
	void*				pvContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxHashData(
	void*				pvContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_HASH_FILE)(
	void*				pvContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileName,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxHashFile(
	void*				pvContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileName,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_HASH_DATA_BEGIN)(
	void*				pvContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	void*				*ppvHashContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxHashDataBegin(
	void*				pvContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	void*				*ppvHashContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_HASH_DATA_CONTINUE)(
	void*				pvHashContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxHashDataContinue(
	void*				pvHashContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_HASH_DATA_END)(
	void*				pvHashContext,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxHashDataEnd(
	void*				pvHashContext,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE_HASH)(
	void*				pvHashContext);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeHash(
	void*				pvHashContext);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_SIGN_HASH)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	void*				pvHashContext,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxSignHash(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	void*				pvHashContext,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_SIGN_HASH_VALUE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxSignHashValue(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_SIGN_DATA)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	int				bExternal,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxSignData(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	int				bExternal,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_SIGN_FILE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	char*				pszInputFile,
	int				bExternal,
	int				bAppendCert,
	char*				pszOutputFile);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxSignFile(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	char*				pszInputFile,
	int				bExternal,
	int				bAppendCert,
	char*				pszOutputFile);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_IS_ALREADY_SIGNED)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	int*				pbIsAlreadySigned);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxIsAlreadySigned(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	int*				pbIsAlreadySigned);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_IS_FILE_ALREADY_SIGNED)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	char*				pszFileNameWithSign,
	int*				pbIsAlreadySigned);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxIsFileAlreadySigned(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	char*				pszFileNameWithSign,
	int*				pbIsAlreadySigned);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_APPEND_SIGN_HASH)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	void*				pvHashContext,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxAppendSignHash(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	void*				pvHashContext,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_APPEND_SIGN_HASH_VALUE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxAppendSignHashValue(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_APPEND_SIGN)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxAppendSign(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	int				bAppendCert,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_APPEND_SIGN_FILE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	char*				pszFileName,
	char*				pszFileNameWithPreviousSign,
	int				bAppendCert,
	char*				pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxAppendSignFile(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	char*				pszFileName,
	char*				pszFileNameWithPreviousSign,
	int				bAppendCert,
	char*				pszFileNameWithSign);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_CREATE_EMPTY_SIGN)(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxCreateEmptySign(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_CREATE_SIGNER)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxCreateSigner(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_APPEND_SIGNER)(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbSigner,
	unsigned long				dwSignerLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxAppendSigner(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbSigner,
	unsigned long				dwSignerLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				pbPreviousSign,
	unsigned long				dwPreviousSignLength,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_SIGNS_COUNT)(
	void*				pvContext,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	unsigned long*				pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetSignsCount(
	void*				pvContext,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	unsigned long*				pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_FILE_SIGNS_COUNT)(
	void*				pvContext,
	char*				pszFileNameWithSign,
	unsigned long*				pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetFileSignsCount(
	void*				pvContext,
	char*				pszFileNameWithSign,
	unsigned long*				pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_SIGNER_INFO)(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetSignerInfo(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_FILE_SIGNER_INFO)(
	void*				pvContext,
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetFileSignerInfo(
	void*				pvContext,
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_VERIFY_HASH)(
	void*				pvHashContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxVerifyHash(
	void*				pvHashContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_VERIFY_HASH_VALUE)(
	void*				pvContext,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxVerifyHashValue(
	void*				pvContext,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_VERIFY_DATA)(
	void*				pvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxVerifyData(
	void*				pvContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_VERIFY_DATA_INTERNAL)(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxVerifyDataInternal(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_VERIFY_FILE)(
	void*				pvContext,
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	char*				pszFileName,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxVerifyFile(
	void*				pvContext,
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	char*				pszFileName,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_ENVELOP_DATA)(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnvelopData(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ENVELOP_FILE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	char*				pszFileName,
	char*				pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnvelopFile(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	char*				pszFileName,
	char*				pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_SENDER_INFO)(
	void*				pvContext,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned char*				pbRecipientCert,
	unsigned long				dwRecipientCertLength,
	int*				pbDynamicKey,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetSenderInfo(
	void*				pvContext,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned char*				pbRecipientCert,
	unsigned long				dwRecipientCertLength,
	int*				pbDynamicKey,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_FILE_SENDER_INFO)(
	void*				pvContext,
	char*				pszEnvelopedFileName,
	unsigned char*				pbRecipientCert, 
	unsigned long				dwRecipientCertLength,
	int*				pbDynamicKey,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetFileSenderInfo(
	void*				pvContext,
	char*				pszEnvelopedFileName,
	unsigned char*				pbRecipientCert, 
	unsigned long				dwRecipientCertLength,
	int*				pbDynamicKey,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_RECIPIENTS_COUNT)(
	void*				pvContext,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned long*				pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetRecipientsCount(
	void*				pvContext,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned long*				pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_FILE_RECIPIENTS_COUNT)(
	void*				pvContext,
	char*				pszEnvelopedFileName,
	unsigned long*				pdwCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetFileRecipientsCount(
	void*				pvContext,
	char*				pszEnvelopedFileName,
	unsigned long*				pdwCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_RECIPIENT_INFO)(
	void*				pvContext,
	unsigned long				dwRecipientIndex,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned long*				pdwRecipientInfoType,
	char*				*ppszRecipientIssuer,
	char*				*ppszRecipientSerial,
	char*				*ppszRecipientPublicKeyID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetRecipientInfo(
	void*				pvContext,
	unsigned long				dwRecipientIndex,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned long*				pdwRecipientInfoType,
	char*				*ppszRecipientIssuer,
	char*				*ppszRecipientSerial,
	char*				*ppszRecipientPublicKeyID);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_FILE_RECIPIENT_INFO)(
	void*				pvContext,
	unsigned long				dwRecipientIndex,
	char*				pszEnvelopedFileName,
	unsigned long*				pdwRecipientInfoType,
	char*				*ppszRecipientIssuer,
	char*				*ppszRecipientSerial,
	char*				*ppszRecipientPublicKeyID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetFileRecipientInfo(
	void*				pvContext,
	unsigned long				dwRecipientIndex,
	char*				pszEnvelopedFileName,
	unsigned long*				pdwRecipientInfoType,
	char*				*ppszRecipientIssuer,
	char*				*ppszRecipientSerial,
	char*				*ppszRecipientPublicKeyID);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ENVELOP_APPEND_DATA)(
	void*				pvPrivateKeyContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbSenderCert,
	unsigned long				dwSenderCertSize,
	unsigned char*				pbPreviousEnvelopedData,
	unsigned long				dwPreviousEnvelopedDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnvelopAppendData(
	void*				pvPrivateKeyContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbSenderCert,
	unsigned long				dwSenderCertSize,
	unsigned char*				pbPreviousEnvelopedData,
	unsigned long				dwPreviousEnvelopedDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ENVELOP_APPEND_FILE)(
	void*				pvPrivateKeyContext,
	char*				pszFileName,
	unsigned char*				pbSenderCert,
	unsigned long				dwSenderCertSize,
	char*				pszPreviousEnvelopedFileName,
	char*				pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnvelopAppendFile(
	void*				pvPrivateKeyContext,
	char*				pszFileName,
	unsigned char*				pbSenderCert,
	unsigned long				dwSenderCertSize,
	char*				pszPreviousEnvelopedFileName,
	char*				pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_ENUM_JKS_PRIVATE_KEYS)(
	unsigned char*				pbContainer,
	unsigned long				dwContainerLength,
	unsigned long				dwIndex,
	char*				*ppszKeyAlias);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumJKSPrivateKeys(
	unsigned char*				pbContainer,
	unsigned long				dwContainerLength,
	unsigned long				dwIndex,
	char*				*ppszKeyAlias);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENUM_JKS_PRIVATE_KEYS_FILE)(
	char*				pszFileName,
	unsigned long				dwIndex,
	char*				*ppszKeyAlias);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumJKSPrivateKeysFile(
	char*				pszFileName,
	unsigned long				dwIndex,
	char*				*ppszKeyAlias);
#endif //PC_STATIC_LIBS

typedef void (*PEU_FREE_CERTIFICATES_ARRAY)(
	unsigned long				dwCertificatesCount,
	unsigned char*				*ppbCertificates,
	unsigned long*				pdwCertificateLengthes);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCertificatesArray(
	unsigned long				dwCertificatesCount,
	unsigned char*				*ppbCertificates,
	unsigned long*				pdwCertificateLengthes);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_JKS_PRIVATE_KEY)(
	unsigned char*				pbContainer,
	unsigned long				dwContainerLength,
	char*				pszKeyAlias,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength,
	unsigned long*				pdwCertificatesCount,
	unsigned char*				**ppbCertificates,
	unsigned long*				*ppdwCertificatesLengthes);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetJKSPrivateKey(
	unsigned char*				pbContainer,
	unsigned long				dwContainerLength,
	char*				pszKeyAlias,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength,
	unsigned long*				pdwCertificatesCount,
	unsigned char*				**ppbCertificates,
	unsigned long*				*ppdwCertificatesLengthes);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_JKS_PRIVATE_KEY_FILE)(
	char*				pszFileName,
	char*				pszKeyAlias,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength,
	unsigned long*				pdwCertificatesCount,
	unsigned char*				**ppbCertificates,
	unsigned long*				*ppdwCertificatesLengthes);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetJKSPrivateKeyFile(
	char*				pszFileName,
	char*				pszKeyAlias,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength,
	unsigned long*				pdwCertificatesCount,
	unsigned char*				**ppbCertificates,
	unsigned long*				*ppdwCertificatesLengthes);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_GET_DATA_FROM_SIGNED_DATA)(
	void*				pvContext,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetDataFromSignedData(
	void*				pvContext,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_DATA_FROM_SIGNED_FILE)(
	void*				pvContext,
	char*				pszFileNameWithSignedData,
	char*				pszFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetDataFromSignedFile(
	void*				pvContext,
	char*				pszFileNameWithSignedData,
	char*				pszFileName);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_SET_SETTINGS_REG_PATH)(
	unsigned long				dwRootKey,
	char*				pszRegPath);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetSettingsRegPath(
	unsigned long				dwRootKey,
	char*				pszRegPath);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_IS_DATA_IN_SIGNED_DATA_AVAILABLE)(
	void*				pvContext,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedLength,
	int*				pbAvailable);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxIsDataInSignedDataAvailable(
	void*				pvContext,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedLength,
	int*				pbAvailable);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_IS_DATA_IN_SIGNED_FILE_AVAILABLE)(
	void*				pvContext,
	char*				pszFileNameWithSignedData,
	int*				pbAvailable);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxIsDataInSignedFileAvailable(
	void*				pvContext,
	char*				pszFileNameWithSignedData,
	int*				pbAvailable);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_CERTIFICATE_FROM_SIGNED_DATA)(
	unsigned long				dwIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateFromSignedData(
	unsigned long				dwIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CERTIFICATE_FROM_SIGNED_FILE)(
	unsigned long				dwIndex,
	char*				pszSignedFile,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateFromSignedFile(
	unsigned long				dwIndex,
	char*				pszSignedFile,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_IS_DATA_IN_SIGNED_DATA_AVAILABLE)(
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	int*				pbAvailable);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsDataInSignedDataAvailable(
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	int*				pbAvailable);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_IS_DATA_IN_SIGNED_FILE_AVAILABLE)(
	char*				pszFileNameWithSignedData,
	int*				pbAvailable);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsDataInSignedFileAvailable(
	char*				pszFileNameWithSignedData,
	int*				pbAvailable);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_DATA_FROM_SIGNED_DATA)(
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetDataFromSignedData(
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_DATA_FROM_SIGNED_FILE)(
	char*				pszFileNameWithSignedData,
	char*				pszFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetDataFromSignedFile(
	char*				pszFileNameWithSignedData,
	char*				pszFileName);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_GET_CERTIFICATES_FROM_LDAP_BY_EDRPOU_CODE)(
	char*				pszEDRPOUCode,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	char*				pszLDAPServers,
	char*				pszLDAPServersPorts,
	unsigned char*				*pbCertificates,
	unsigned long*				pdwCertificates);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificatesFromLDAPByEDRPOUCode(
	char*				pszEDRPOUCode,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	char*				pszLDAPServers,
	char*				pszLDAPServersPorts,
	unsigned char*				*pbCertificates,
	unsigned long*				pdwCertificates);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_PROTECT_DATA_BY_PASSWORD)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				pszPassword,
	char*				*ppszProtectedData,
	unsigned char*				*ppbProtectedData,
	unsigned long*				pdwProtectedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUProtectDataByPassword(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				pszPassword,
	char*				*ppszProtectedData,
	unsigned char*				*ppbProtectedData,
	unsigned long*				pdwProtectedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_UNPROTECT_DATA_BY_PASSWORD)(
	char*				pszProtectedData,
	unsigned char*				pbProtectedData,
	unsigned long				dwProtectedDataLength,
	char*				pszPassword,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUUnprotectDataByPassword(
	char*				pszProtectedData,
	unsigned char*				pbProtectedData,
	unsigned long				dwProtectedDataLength,
	char*				pszPassword,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef void (*PEU_FREE_TIME_INFO)(
	PEU_TIME_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeTimeInfo(
	PEU_TIME_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_SIGN_TIME_INFO)(
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PPEU_TIME_INFO		ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetSignTimeInfo(
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PPEU_TIME_INFO		ppInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_FILE_SIGN_TIME_INFO)(
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	PPEU_TIME_INFO		ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileSignTimeInfo(
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	PPEU_TIME_INFO		ppInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_HASH_ON_TIME)(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyHashOnTime(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_ON_TIME)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataOnTime(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_INTERNAL_ON_TIME)(
	unsigned long				dwSignIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PSYSTEMTIME			pOnTime,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataInternalOnTime(
	unsigned long				dwSignIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PSYSTEMTIME			pOnTime,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_ON_TIME_BEGIN)(
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataOnTimeBegin(
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_FILE_ON_TIME)(
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	char*				pszFileName,
	PSYSTEMTIME			pOnTime,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyFileOnTime(
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	char*				pszFileName,
	PSYSTEMTIME			pOnTime,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_VERIFY_HASH_ON_TIME_EX)(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyHashOnTimeEx(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_ON_TIME_EX)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataOnTimeEx(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_INTERNAL_ON_TIME_EX)(
	unsigned long				dwSignIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataInternalOnTimeEx(
	unsigned long				dwSignIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_ON_TIME_BEGIN_EX)(
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataOnTimeBeginEx(
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_FILE_ON_TIME_EX)(
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	char*				pszFileName,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyFileOnTimeEx(
	unsigned long				dwSignIndex,
	char*				pszFileNameWithSign,
	char*				pszFileName,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_CTX_ENUM_PRIVATE_KEY_INFO)(
	void*				pvPrivateKeyContext,
	unsigned long				dwIndex,
	unsigned long*				pdwKeyType,
	unsigned long*				pdwKeyUsage,
	unsigned long*				pdwKeyIDs,
	char*				*ppszKeyIDs);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnumPrivateKeyInfo(
	void*				pvPrivateKeyContext,
	unsigned long				dwIndex,
	unsigned long*				pdwKeyType,
	unsigned long*				pdwKeyUsage,
	unsigned long*				pdwKeyIDs,
	char*				*ppszKeyIDs);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_EXPORT_PRIVATE_KEY_CONTAINER)(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	char*				pszKeyID,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxExportPrivateKeyContainer(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	char*				pszKeyID,
	unsigned char*				*ppbPrivateKey,
	unsigned long*				pdwPrivateKeyLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_EXPORT_PRIVATE_KEY_PFX_CONTAINER)(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	int				bExportCerts,
	unsigned long				dwKeyIDs,
	int*				pbTrustedKeyIDs,
	char*				pszKeyIDs,
	unsigned char*				*ppbPFXContainer,
	unsigned long*				pdwPFXContainerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxExportPrivateKeyPFXContainer(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	int				bExportCerts,
	unsigned long				dwKeyIDs,
	int*				pbTrustedKeyIDs,
	char*				pszKeyIDs,
	unsigned char*				*ppbPFXContainer,
	unsigned long*				pdwPFXContainerLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_EXPORT_PRIVATE_KEY_CONTAINER_FILE)(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	char*				pszKeyID,
	char*				pszFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxExportPrivateKeyContainerFile(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	char*				pszKeyID,
	char*				pszFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_EXPORT_PRIVATE_KEY_PFX_CONTAINER_FILE)(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	int				bExportCerts,
	unsigned long				dwKeyIDs,
	int*				pbTrustedKeyIDs,
	char*				pszKeyIDs,
	char*				pszFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxExportPrivateKeyPFXContainerFile(
	void*				pvPrivateKeyContext,
	char*				pszPassword,
	int				bExportCerts,
	unsigned long				dwKeyIDs,
	int*				pbTrustedKeyIDs,
	char*				pszKeyIDs,
	char*				pszFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_CERTIFICATE_FROM_PRIVATE_KEY)(
	void*				pvPrivateKeyContext,
	char*				pszKeyID,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetCertificateFromPrivateKey(
	void*				pvPrivateKeyContext,
	char*				pszKeyID,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS
//=============================================================================

typedef unsigned long (*PEU_RAW_ENVELOP_DATA)(
	unsigned char*				pbRecipientCert,
	unsigned long				dwRecipientCertLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				*ppszEnvelopedData,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawEnvelopData(
	unsigned char*				pbRecipientCert,
	unsigned long				dwRecipientCertLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				*ppszEnvelopedData,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RAW_DEVELOP_DATA)(
	char*				pszEnvelopedData,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_ENVELOP_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawDevelopData(
	char*				pszEnvelopedData,
	unsigned char*				pbEnvelopedData,
	unsigned long				dwEnvelopedDataLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_ENVELOP_INFO	pInfo);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_RAW_VERIFY_DATA_EX)(
	unsigned char*				pbCert,
	unsigned long				dwCertLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURawVerifyDataEx(
	unsigned char*				pbCert,
	unsigned long				dwCertLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_DATA_RSA_EX)(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataRSAEx(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_DATA_RSA)(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataRSA(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_FILE_RSA_EX)(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileRSAEx(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuers,
	char*			pszRecipientCertSerials,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_FILE_RSA)(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileRSA(
	unsigned long			dwContentEncAlgoType,
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_RECEIVERS_CERTIFICATES_RSA)(
	PPEU_CERTIFICATES
					ppCertificates);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetReceiversCertificatesRSA(
	PPEU_CERTIFICATES
					ppCertificates);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS_RSA)(
	unsigned long			dwContentEncAlgoType,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataToRecipientsRSA(
	unsigned long			dwContentEncAlgoType,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ENVELOP_FILE_TO_RECIPIENTS_RSA)(
	unsigned long			dwContentEncAlgoType,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopFileToRecipientsRSA(
	unsigned long			dwContentEncAlgoType,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	char*			pszFileName,
	char*			pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_REMOVE_SIGN)(
	unsigned long			dwSignIndex,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURemoveSign(
	unsigned long			dwSignIndex,
	char*			pszPreviousSign,
	unsigned char*			pbPreviousSign,
	unsigned long			dwPreviousSignLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_REMOVE_SIGN_FILE)(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithPreviousSign,
	char*			pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURemoveSignFile(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithPreviousSign,
	char*			pszFileNameWithSign);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_DEV_CTX_ENUM)(
	void*				pvDeviceContext,
	char*				pszDeviceDescription);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxEnum(
	void*				pvDeviceContext,
	char*				pszDeviceDescription);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_OPEN)(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	void*			*ppvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxOpen(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	void*			*ppvDeviceContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_ENUM_VIRTUAL)(
	void*			*ppvDeviceContext,
	char*			pszTypeDescription);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxEnumVirtual(
	void*			*ppvDeviceContext,
	char*			pszTypeDescription);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_OPEN_VIRTUAL)(
	const char*			pszTypeDescription,
	void*			*ppvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxOpenVirtual(
	const char*			pszTypeDescription,
	void*			*ppvDeviceContext);
#endif //PC_STATIC_LIBS

typedef void (*PEU_DEV_CTX_CLOSE)(
	void*			pvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
void EUDevCtxClose(
	void*			pvDeviceContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_BEGIN_PERSONALIZATION)(
	void*			pvDeviceContext,
	unsigned char*			pbDeviceSerialNumber,
	unsigned long			dwDeviceSerialNumberLength,
	unsigned char*			pbSystemCertificate,
	unsigned long			dwSystemCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxBeginPersonalization(
	void*			pvDeviceContext,
	unsigned char*			pbDeviceSerialNumber,
	unsigned long			dwDeviceSerialNumberLength,
	unsigned char*			pbSystemCertificate,
	unsigned long			dwSystemCertificateLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_CONTINUE_PERSONALIZATION)(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxContinuePersonalization(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_END_PERSONALIZATION)(
	void*			pvDeviceContext,
	unsigned char*			pbSystemPublicKeyVersion,
	unsigned short*			pwUpdateCounter);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxEndPersonalization(
	void*			pvDeviceContext,
	unsigned char*			pbSystemPublicKeyVersion,
	unsigned short*			pwUpdateCounter);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_DATA)(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxGetData(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_UPDATE_DATA)(
	void*			pvDeviceContext,
	unsigned char			bSystemPublicKeyVersion,
	unsigned short			wUpdateCounter,
	unsigned char			bTag,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			pbSignature,
	unsigned long			dwSignatureLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxUpdateData(
	void*			pvDeviceContext,
	unsigned char			bSystemPublicKeyVersion,
	unsigned short			wUpdateCounter,
	unsigned char			bTag,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			pbSignature,
	unsigned long			dwSignatureLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_SIGN_DATA)(
	void*				pvDeviceContext,
	void*				pvPrivateKeyContext,
	unsigned char*				pbDeviceSerialNumber,
	unsigned long				dwDeviceSerialNumber,
	unsigned char				bSystemPublicKeyVersion,
	unsigned short				wUpdateCounter,
	unsigned char				bTag,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbSignature,
	unsigned long*				pdwSignatureLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxSignData(
	void*				pvDeviceContext,
	void*				pvPrivateKeyContext,
	unsigned char*				pbDeviceSerialNumber,
	unsigned long				dwDeviceSerialNumber,
	unsigned char				bSystemPublicKeyVersion,
	unsigned short				wUpdateCounter,
	unsigned char				bTag,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbSignature,
	unsigned long*				pdwSignatureLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_CHANGE_PASSWORD)(
	void*				pvDeviceContext,
	const char*				pszPassword);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxChangePassword(
	void*				pvDeviceContext,
	const char*				pszPassword);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_UPDATE_SYSTEM_PUBLIC_KEY)(
	void*			pvDeviceContext,
	unsigned char			bSystemPublicKeyVersion,
	unsigned short			wUpdateCounter,
	unsigned char*			pbSystemCertificate,
	unsigned long			dwSystemCertificateLength,
	unsigned char*			pbSignature,
	unsigned long			dwSignatureLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxUpdateSystemPublicKey(
	void*			pvDeviceContext,
	unsigned char			bSystemPublicKeyVersion,
	unsigned short			wUpdateCounter,
	unsigned char*			pbSystemCertificate,
	unsigned long			dwSystemCertificateLength,
	unsigned char*			pbSignature,
	unsigned long			dwSignatureLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_SIGN_SYSTEM_PUBLIC_KEY)(
	void*				pvDeviceContext,
	void*				pvPrivateKeyContext,
	unsigned char*				pbDeviceSerialNumber,
	unsigned long				dwDeviceSerialNumber,
	unsigned char				bSystemPublicKeyVersion,
	unsigned short				wUpdateCounter,
	unsigned char*				pbSystemCertificate,
	unsigned long				dwSystemCertificateLength,
	unsigned char*				*ppbSignature,
	unsigned long*				pdwSignatureLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxSignSystemPublicKey(
	void*				pvDeviceContext,
	void*				pvPrivateKeyContext,
	unsigned char*				pbDeviceSerialNumber,
	unsigned long				dwDeviceSerialNumber,
	unsigned char				bSystemPublicKeyVersion,
	unsigned short				wUpdateCounter,
	unsigned char*				pbSystemCertificate,
	unsigned long				dwSystemCertificateLength,
	unsigned char*				*ppbSignature,
	unsigned long*				pdwSignatureLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_RECEIVERS_CERTIFICATES_EX)(
	char*				pszCaption,
	char*				pszTitle,
	unsigned long				dwCertKeyType,
	int				bOnlyOne,
	PPEU_CERTIFICATES	ppCertificates);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetReceiversCertificatesEx(
	char*				pszCaption,
	char*				pszTitle,
	unsigned long				dwCertKeyType,
	int				bOnlyOne,
	PPEU_CERTIFICATES	ppCertificates);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_APPEND_TRANSPORT_HEADER)(
	char*				pszCAType,
	char*				pszFileName,
	char*				pszClientEMail,
	unsigned char*				pbClientCert,
	unsigned long				dwClientCertLength,
	unsigned char*				pbCryptoData,
	unsigned long				dwCryptoDataLength,
	unsigned char*				*ppbTransportData,
	unsigned long*				pdwTransportDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAppendTransportHeader(
	char*				pszCAType,
	char*				pszFileName,
	char*				pszClientEMail,
	unsigned char*				pbClientCert,
	unsigned long				dwClientCertLength,
	unsigned char*				pbCryptoData,
	unsigned long				dwCryptoDataLength,
	unsigned char*				*ppbTransportData,
	unsigned long*				pdwTransportDataLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_PARSE_TRANSPORT_HEADER)(
	unsigned char*				pbTransportData,
	unsigned long				dwTransportDataLength,
	unsigned long*				pdwReceiptNumber,
	unsigned char*				*ppbCryptoData,
	unsigned long*				pdwCryptoDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUParseTransportHeader(
	unsigned char*				pbTransportData,
	unsigned long				dwTransportDataLength,
	unsigned long*				pdwReceiptNumber,
	unsigned char*				*ppbCryptoData,
	unsigned long*				pdwCryptoDataLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_APPEND_CRYPTO_HEADER)(
	char*				pszCAType,
	unsigned long				dwHeaderType,
	unsigned char*				pbCryptoData,
	unsigned long				dwCryptoDataLength,
	unsigned char*				*ppbTransportData,
	unsigned long*				pdwTransportDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAppendCryptoHeader(
	char*				pszCAType,
	unsigned long				dwHeaderType,
	unsigned char*				pbCryptoData,
	unsigned long				dwCryptoDataLength,
	unsigned char*				*ppbTransportData,
	unsigned long*				pdwTransportDataLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_PARSE_CRYPTO_HEADER)(
	unsigned char*				pbTransportData,
	unsigned long				dwTransportDataLength,
	char*				pszCAType,
	unsigned long*				pdwHeaderType,
	unsigned long*				pdwHeaderSize,
	unsigned char*				*ppbCryptoData,
	unsigned long*				pdwCryptoDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUParseCryptoHeader(
	unsigned char*				pbTransportData,
	unsigned long				dwTransportDataLength,
	char*				pszCAType,
	unsigned long*				pdwHeaderType,
	unsigned long*				pdwHeaderSize,
	unsigned char*				*ppbCryptoData,
	unsigned long*				pdwCryptoDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS_OFFLINE)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertsOffline,
	int			bCheckRecipientCertsNoCRL,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUEnvelopDataToRecipientsOffline(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertOffline,
	int			bCheckRecipientCertNoCRL,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_GENERATE_PRIVATE_KEY)(
	void*			pvDeviceContext,
	unsigned long			dwUADSKeysSpec,
	unsigned long			dwUAKEPKeysSpec,
	unsigned char*			*ppbUARequest,
	unsigned long*			pdwUARequest,
	unsigned char*			*ppbUAKEPRequest,
	unsigned long*			pdwUAKEPRequest);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxGeneratePrivateKey(
	void*			pvDeviceContext,
	unsigned long			dwUADSKeysSpec,
	unsigned long			dwUAKEPKeysSpec,
	unsigned char*			*ppbUARequest,
	unsigned long*			pdwUARequest,
	unsigned char*			*ppbUAKEPRequest,
	unsigned long*			pdwUAKEPRequest);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GENERATE_PRNG_SEQUENCE)(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGeneratePRNGSequence(
	unsigned char*			pbData,
	unsigned long			dwDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SET_SETTINGS_FILE_PATH_EX)(
	char*			pszSettingsFilePath,
	unsigned long			dwRootKey,
	char*			pszRegPath);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetSettingsFilePathEx(
	char*			pszSettingsFilePath,
	unsigned long			dwRootKey,
	char*			pszRegPath);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CHANGE_OWN_CERTIFICATES_STATUS)(
	unsigned long				dwRequestType,
	unsigned long				dwRevocationReason);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUChangeOwnCertificatesStatus(
	unsigned long				dwRequestType,
	unsigned long				dwRevocationReason);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_CHANGE_OWN_CERTIFICATES_STATUS)(
	void*				pvPrivateKeyContext,
	unsigned long				dwRequestType,
	unsigned long				dwRevocationReason);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxChangeOwnCertificatesStatus(
	void*				pvPrivateKeyContext,
	unsigned long				dwRequestType,
	unsigned long				dwRevocationReason);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_CERTIFICATES_BY_NBU_CODE_AND_CMP)(
	char*			pszNBUCode,
	unsigned long			dwCertKeyType,
	unsigned long			dwKeyUsage,
	PSYSTEMTIME		pOnTime,
	unsigned char*			*ppbCertificates,
	unsigned long*			pdwCertificatesLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificatesByNBUCodeAndCMP(
	char*			pszNBUCode,
	unsigned long			dwCertKeyType,
	unsigned long			dwKeyUsage,
	PSYSTEMTIME		pOnTime,
	unsigned char*			*ppbCertificates,
	unsigned long*			pdwCertificatesLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ENUM_CERTIFICATES_EX)(
	unsigned long				dwSubjectType,
	unsigned long				dwSubjectSubType,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	unsigned long				dwIndex,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnumCertificatesEx(
	unsigned long				dwSubjectType,
	unsigned long				dwSubjectSubType,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	unsigned long				dwIndex,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_MAKE_NEW_CERTIFICATE)(
	PEU_KEY_MEDIA		pOldKeyMedia,
	unsigned char*				pbOldPrivateKey,
	unsigned long				dwOldPrivateKeyLength,
	char*				pszOldPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_KEY_MEDIA		pNewKeyMedia,
	char*				pszNewPrivateKeyPassword,
	unsigned char*				*ppbNewPrivateKey,
	unsigned long*				pdwNewPrivateKeyLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUMakeNewCertificate(
	PEU_KEY_MEDIA		pOldKeyMedia,
	unsigned char*				pbOldPrivateKey,
	unsigned long				dwOldPrivateKeyLength,
	char*				pszOldPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_KEY_MEDIA		pNewKeyMedia,
	char*				pszNewPrivateKeyPassword,
	unsigned char*				*ppbNewPrivateKey,
	unsigned long*				pdwNewPrivateKeyLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CREATE_SIGNER_BEGIN)(
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateSignerBegin(
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CREATE_SIGNER_END)(
	unsigned char*				pbUnsignedSigner,
	unsigned long				dwUnsignedSignerLength,
	unsigned char*				pbSignarure,
	unsigned long				dwSignatureLength,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateSignerEnd(
	unsigned char*				pbUnsignedSigner,
	unsigned long				dwUnsignedSignerLength,
	unsigned char*				pbSignarure,
	unsigned long				dwSignatureLength,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CLIENT_DYNAMIC_KEY_SESSION_LOAD)(
	unsigned char*			pbSessionData,
	unsigned long			dwSessionDataLength,
	void*			*ppvSession);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUClientDynamicKeySessionLoad(
	unsigned char*			pbSessionData,
	unsigned long			dwSessionDataLength,
	void*			*ppvSession);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_OPEN_IDCARD)(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	unsigned long			dwPasswordVersion,
	void*			*ppvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxOpenIDCard(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	unsigned long			dwPasswordVersion,
	void*			*ppvDeviceContext);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_DEV_CTX_CHANGE_IDCARD_PASSWORDS)(
	void*				pvDeviceContext,
	const char*				pszPIN,
	const char*				pszPUK);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxChangeIDCardPasswords(
	void*				pvDeviceContext,
	const char*				pszPIN,
	const char*				pszPUK);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_DEV_CTX_AUTHENTICATE_IDCARD)(
	void*				pvDeviceContext,
	const char*				pszParameter1,
	const char*				pszParameter2);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxAuthenticateIDCard(
	void*				pvDeviceContext,
	const char*				pszParameter1,
	const char*				pszParameter2);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_DEV_CTX_VERIFY_IDCARD_DATA)(
	void*				pvDeviceContext,
	unsigned char				bTag);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxVerifyIDCardData(
	void*				pvDeviceContext,
	unsigned char				bTag);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_DEV_CTX_UPDATE_IDCARD_DATA)(
	void*				pvDeviceContext,
	void*				pvPrivateKeyContext,
	unsigned char				bTag,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxUpdateIDCardData(
	void*				pvDeviceContext,
	void*				pvPrivateKeyContext,
	unsigned char				bTag,
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_DEV_CTX_ENUM_IDCARD_DATA)(
	void*				pvDeviceContext,
	unsigned char				bTag,
	unsigned long				dwIndex,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxEnumIDCardData(
	void*				pvDeviceContext,
	unsigned char				bTag,
	unsigned long				dwIndex,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_DATA_WITH_SETTINGS)(
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertOffline,
	int			bCheckRecipientCertNoCRL,
	int			bNoTSP,
	int			bAppendCert,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUEnvelopDataWithSettings(
	char*			pszRecipientCertIssuer,
	char*			pszRecipientCertSerial,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertOffline,
	int			bCheckRecipientCertNoCRL,
	int			bNoTSP,
	int			bAppendCert,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_SETTINGS)(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertsOffline,
	int			bCheckRecipientCertsNoCRL,
	int			bNoTSP,
	int			bAppendCert,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUEnvelopDataToRecipientsWithSettings(
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertsOffline,
	int			bCheckRecipientCertsNoCRL,
	int			bNoTSP,
	int			bAppendCert,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef int (*PEU_SHOW_SECURE_CONFIRM_DIALOG)(
	char*			pszCaption,
	char*			pszLabel,
	char*			pszFooter);
#ifdef PC_STATIC_LIBS
extern "C"
int EUShowSecureConfirmDialog(
	char*			pszCaption,
	char*			pszLabel,
	char*			pszFooter);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_CLIENT_SESSION_CREATE_STEP1)(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxClientSessionCreateStep1(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_SERVER_SESSION_CREATE_STEP1)(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxServerSessionCreateStep1(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_SESSION_LOAD)(
	void*			pvPrivateKeyContext,
	unsigned char*			pbSessionData,
	unsigned long			dwSessionDataLength,
	void*			*ppvSession);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxSessionLoad(
	void*			pvPrivateKeyContext,
	unsigned char*			pbSessionData,
	unsigned long			dwSessionDataLength,
	void*			*ppvSession);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_SERVER_DYNAMIC_KEY_SESSION_CREATE)(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxServerDynamicKeySessionCreate(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_GET_SIGN_VALUE)(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			*ppbSignValue,
	unsigned long*			pdwSignValueLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxGetSignValue(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			*ppbSignValue,
	unsigned long*			pdwSignValueLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_APPEND_SIGNER_UNSIGNED_ATTRIBUTE)(
	char*			pszPreviousSigner,
	unsigned char*			pbPreviousSigner,
	unsigned long			dwPreviousSignerLength,
	char*			pszAttrOID,
	unsigned char*			pbAttrValue,
	unsigned long			dwAttrValueLength,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAppendSignerUnsignedAttribute(
	char*			pszPreviousSigner,
	unsigned char*			pbPreviousSigner,
	unsigned long			dwPreviousSignerLength,
	char*			pszAttrOID,
	unsigned char*			pbAttrValue,
	unsigned long			dwAttrValueLength,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CHECK_CERTIFICATE_BY_OCSP)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCheckCertificateByOCSP(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_OCSP_RESPONSE)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			*ppbOCSPResponse,
	unsigned long*			pdwOCSPResponseLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetOCSPResponse(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			*ppbOCSPResponse,
	unsigned long*			pdwOCSPResponseLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CHECK_OCSP_RESPONSE)(
	unsigned char*			pbOCSPResponse,
	unsigned long			dwOCSPResponseLength,
	PSYSTEMTIME		pOnTime);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCheckOCSPResponse(
	unsigned char*			pbOCSPResponse,
	unsigned long			dwOCSPResponseLength,
	PSYSTEMTIME		pOnTime);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CHECK_CERTIFICATE_BY_OCSP_RESPONSE)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			pbOCSPResponse,
	unsigned long			dwOCSPResponseLength,
	PSYSTEMTIME		pOnTime);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCheckCertificateByOCSPResponse(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			pbOCSPResponse,
	unsigned long			dwOCSPResponseLength,
	PSYSTEMTIME		pOnTime);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CREATE_REVOCATION_INFO_ATTRIBUTES)(
	unsigned long			dwRevocationReferences,
	unsigned long			dwOCSPResponses,
	unsigned char*			*ppbOCSPResponses,
	unsigned long*			pdwOCSPResponsesLengthes,
	unsigned char*			*ppbRevocationReferencesAttr,
	unsigned long*			pdwRevocationReferencesAttrLength,
	unsigned char*			*ppbRevocationValuesAttr,
	unsigned long*			pdwRevocationValuesAttrLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCreateRevocationInfoAttributes(
	unsigned long			dwRevocationReferences,
	unsigned long			dwOCSPResponses,
	unsigned char*			*ppbOCSPResponses,
	unsigned long*			pdwOCSPResponsesLengthes,
	unsigned char*			*ppbRevocationReferencesAttr,
	unsigned long*			pdwRevocationReferencesAttrLength,
	unsigned char*			*ppbRevocationValuesAttr,
	unsigned long*			pdwRevocationValuesAttrLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CERTIFICATE_CHAIN)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned long*			pdwCACertificatesCount,
	unsigned char*			**ppbCACertificates,
	unsigned long*			*ppdwCACertificatesLengthes);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetCertificateChain(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned long*			pdwCACertificatesCount,
	unsigned char*			**ppbCACertificates,
	unsigned long*			*ppdwCACertificatesLengthes);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CREATE_CA_CERTIFICATE_INFO_ATTRIBUTES)(
	unsigned long			dwCACertificates,
	unsigned char*			*ppbCACertificates,
	unsigned long*			pdwCACertificatesLengthes,
	unsigned char*			*ppbCertificateReferencesAttr,
	unsigned long*			pdwCertificateReferencesAttrLength,
	unsigned char*			*ppbCertificateValuesAttr,
	unsigned long*			pdwCertificateValuesAttrLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCreateCACertificateInfoAttributes(
	unsigned long			dwCACertificates,
	unsigned char*			*ppbCACertificates,
	unsigned long*			pdwCACertificatesLengthes,
	unsigned char*			*ppbCertificateReferencesAttr,
	unsigned long*			pdwCertificateReferencesAttrLength,
	unsigned char*			*ppbCertificateValuesAttr,
	unsigned long*			pdwCertificateValuesAttrLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_TSP)(
	unsigned long			dwHashAlgo,
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			*ppbTSP,
	unsigned long*			pdwTSPLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetTSP(
	unsigned long			dwHashAlgo,
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			*ppbTSP,
	unsigned long*			pdwTSPLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CHECK_TSP)(
	unsigned char*			pbTSP,
	unsigned long			dwTSPLength,
	unsigned long			dwHashAlgo,
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCheckTSP(
	unsigned char*			pbTSP,
	unsigned long			dwTSPLength,
	unsigned long			dwHashAlgo,
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_CLIENT_SESSION_CREATE)(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbServerCert,
	unsigned long			dwServerCertLength,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxClientSessionCreate(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbServerCert,
	unsigned long			dwServerCertLength,
	void*			*ppvClientSession,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_SERVER_SESSION_CREATE)(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxServerSessionCreate(
	void*			pvPrivateKeyContext,
	unsigned long			dwExpireTime,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_IS_NAMED_PRIVATE_KEY_EXISTS)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	int*				pbExists);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxIsNamedPrivateKeyExists(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	int*				pbExists);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_GENERATE_NAMED_PRIVATE_KEY)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGenerateNamedPrivateKey(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_READ_NAMED_PRIVATE_KEY)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	void*				*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxReadNamedPrivateKey(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	void*				*ppvPrivateKeyContext,
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_DESTROY_NAMED_PRIVATE_KEY)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxDestroyNamedPrivateKey(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_CHANGE_NAMED_PRIVATE_KEY_PASSWORD)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	char*				pszNamedPrivateKeyNewPassword);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxChangeNamedPrivateKeyPassword(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	char*				pszNamedPrivateKeyNewPassword);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_TSP_BY_ACCESS_INFO)(
	unsigned long				dwHashAlgo,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				pszAccessInfo,
	char*				pszAccessInfoPort,
	unsigned char*				*ppbTSP,
	unsigned long*				pdwTSPLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetTSPByAccessInfo(
	unsigned long				dwHashAlgo,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				pszAccessInfo,
	char*				pszAccessInfoPort,
	unsigned char*				*ppbTSP,
	unsigned long*				pdwTSPLength);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CERTIFICATE_BY_FINGERPRINT)(
	char*				pszFingerprint,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetCertificateByFingerprint(
	char*				pszFingerprint,
	PEU_CERT_INFO_EX	*ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef void (*PEU_FREE_CERTIFICATES)(
	PEU_CERTIFICATES	pCertificates);
#ifdef PC_STATIC_LIBS
extern "C" void EUFreeCertificates(
	PEU_CERTIFICATES	pCertificates);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_CERTIFICATES_BY_EDRPOU_AND_DRFO_CODE)(
	char*				pszEDRPOUCode,
	char*				pszDRFOCode,
	int				bStamp,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PSYSTEMTIME			pOnTime,
	PPEU_CERTIFICATES	ppCertificates);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetCertificatesByEDRPOUAndDRFOCode(
	char*				pszEDRPOUCode,
	char*				pszDRFOCode,
	int				bStamp,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	PSYSTEMTIME			pOnTime,
	PPEU_CERTIFICATES	ppCertificates);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SET_OCSP_RESPONSE_EXPIRE_TIME)(
	unsigned long				dwExpireTime);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSetOCSPResponseExpireTime(
	unsigned long				dwExpireTime);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_OCSP_RESPONSE_BY_ACCESS_INFO)(
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszAccessInfo,
	char*				pszAccessInfoPort,
	unsigned char*				*ppbOCSPResponse,
	unsigned long*				pdwOCSPResponseLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetOCSPResponseByAccessInfo(
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszAccessInfo,
	char*				pszAccessInfoPort,
	unsigned char*				*ppbOCSPResponse,
	unsigned long*				pdwOCSPResponseLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DELETE_CERTIFICATE)(
	char*				pszIssuer,
	char*				pszSerial);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDeleteCertificate(
	char*				pszIssuer,
	char*				pszSerial);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SET_KEY_MEDIA_USER_PASSWORD)(
	char*				pszSOPassword,
	PEU_KEY_MEDIA		pKeyMedia);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetKeyMediaUserPassword(
	char*				pszSOPassword,
	PEU_KEY_MEDIA		pKeyMedia);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CHECK_DATA_STRUCT)(
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCheckDataStruct(
	unsigned char*				pbData,
	unsigned long				dwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CHECK_FILE_STRUCT)(
	char*				pszFileName);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCheckFileStruct(
	char*				pszFileName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_ENUM_IDCARD_DATA_CHANGE_DATE)(
	void*				pvDeviceContext,
	unsigned char				bTag,
	unsigned long				dwIndex,
	PSYSTEMTIME			pChangeDate);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxEnumIDCardDataChangeDate(
	void*				pvDeviceContext,
	unsigned char				bTag,
	unsigned long				dwIndex,
	PSYSTEMTIME			pChangeDate);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_DATA_HASH_FROM_SIGNED_DATA)(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetDataHashFromSignedData(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_DATA_HASH_FROM_SIGNED_FILE)(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSignedData,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetDataHashFromSignedFile(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSignedData,
	char*			*ppszHash,
	unsigned char*			*ppbHash,
	unsigned long*			pdwHashLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_VERIFY_IDCARD_SECURITY_OBJECT_DOCUMENT)(
	void*				pvDeviceContext,
	char*				pszCertificatesStorePath);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxVerifyIDCardSecurityObjectDocument(
	void*				pvDeviceContext,
	char*				pszCertificatesStorePath);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_VERIFY_DATA_WITH_PARAMS)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	int				bNoSignerCertCheck,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataWithParams(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned long				dwSignIndex,
	char*				pszSign,
	unsigned char*				pbSign,
	unsigned long				dwSignLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	int				bNoSignerCertCheck,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_VERIFY_DATA_INTERNAL_WITH_PARAMS)(
	unsigned long				dwSignIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	int				bNoSignerCertCheck,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUVerifyDataInternalWithParams(
	unsigned long				dwSignIndex,
	char*				pszSignedData,
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	PSYSTEMTIME			pOnTime,
	int				bOffline,
	int				bNoCRL,
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	int				bNoSignerCertCheck,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_GET_NAMED_PRIVATE_KEY_INFO)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetNamedPrivateKeyInfo(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfo);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_CERTIFICATE_BY_KEY_INFO_EX)(
	unsigned long				dwTypeIndex,
	unsigned long				dwDevIndex,
	unsigned char*				pbPrivKeyInfo,
	unsigned long				dwPrivKeyInfo,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateByKeyInfoEx(
	unsigned long				dwTypeIndex,
	unsigned long				dwDevIndex,
	unsigned char*				pbPrivKeyInfo,
	unsigned long				dwPrivKeyInfo,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef void (*PEU_SHOW_CERTIFICATE)(
	char*				pszCaption,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" void EUShowCertificate(
	char*				pszCaption,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_APPEND_FILE_TRANSPORT_HEADER)(
	char*				pszCAType,
	char*				pszFileName,
	char*				pszClientEMail,
	unsigned char*				pbClientCert,
	unsigned long				dwClientCertLength,
	char*				pszFileWithCryptoData,
	char*				pszFileWithTransportData);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAppendFileTransportHeader(
	char*				pszCAType,
	char*				pszFileName,
	char*				pszClientEMail,
	unsigned char*				pbClientCert,
	unsigned long				dwClientCertLength,
	char*				pszFileWithCryptoData,
	char*				pszFileWithTransportData);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_PARSE_FILE_TRANSPORT_HEADER)(
	char*				pszFileWithTransportData,
	unsigned long*				pdwReceiptNumber,
	char*				pszFileWithCryptoData);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUParseFileTransportHeader(
	char*				pszFileWithTransportData,
	unsigned long*				pdwReceiptNumber,
	char*				pszFileWithCryptoData);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_APPEND_FILE_CRYPTO_HEADER)(
	char*				pszCAType,
	unsigned long				dwHeaderType,
	char*				pszFileWithCryptoData,
	char*				pszFileWithTransportData);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAppendFileCryptoHeader(
	char*				pszCAType,
	unsigned long				dwHeaderType,
	char*				pszFileWithCryptoData,
	char*				pszFileWithTransportData);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_PARSE_FILE_CRYPTO_HEADER)(
	char*				pszFileWithTransportData,
	char*				pszCAType,
	unsigned long*				pdwHeaderType,
	unsigned long*				pdwHeaderSize,
	char*				pszFileWithCryptoData);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUParseFileCryptoHeader(
	char*				pszFileWithTransportData,
	char*				pszCAType,
	unsigned long*				pdwHeaderType,
	unsigned long*				pdwHeaderSize,
	char*				pszFileWithCryptoData);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef void (*PEU_FREE_KEY_MEDIA_DEVICE_INFO)(
	PEU_KEY_MEDIA_DEVICE_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C"
void EUFreeKeyMediaDeviceInfo(
	PEU_KEY_MEDIA_DEVICE_INFO	pInfo);
#endif //PC_STATIC_LIBS

//----------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_KEY_MEDIA_DEVICE_INFO)(
	PEU_KEY_MEDIA				pKeyMedia,
	PPEU_KEY_MEDIA_DEVICE_INFO	ppInfo);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetKeyMediaDeviceInfo(
	PEU_KEY_MEDIA				pKeyMedia,
	PPEU_KEY_MEDIA_DEVICE_INFO	ppInfo);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_ENUM_NAMED_PRIVATE_KEYS)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	unsigned long				dwIndex,
	char*				pszNamedPrivateKeyLabel);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxEnumNamedPrivateKeys(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	unsigned long				dwIndex,
	char*				pszNamedPrivateKeyLabel);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_INTERNAL_AUTHENTICATE_IDCARD)(
	void*				pvDeviceContext,
	unsigned long				dwCVCertificates,
	unsigned char*				*ppbCVCertificates,
	unsigned long*				pdwCVCertificatesLength,
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	const char*				pszPassword);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxInternalAuthenticateIDCard(
	void*				pvDeviceContext,
	unsigned long				dwCVCertificates,
	unsigned char*				*ppbCVCertificates,
	unsigned long*				pdwCVCertificatesLength,
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	const char*				pszPassword);
#endif //PC_STATIC_LIBS

//=============================================================================

typedef unsigned long (*PEU_RECOVER_KEY_INFO)(
	PEU_KEY_MEDIA	pKeyMedia,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURecoverKeyInfo(
	PEU_KEY_MEDIA	pKeyMedia,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RECOVER_KEY_INFO_BINARY)(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURecoverKeyInfoBinary(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_RECOVER_KEY_INFO_FILE)(
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURecoverKeyInfoFile(
	char*			pszPrivateKeyFileName,
	char*			pszPassword,
	unsigned char*			*ppbPrivKeyInfo,
	unsigned long*			pdwPrivKeyInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_READ_AND_RECOVER_PRIVATE_KEY_BINARY)(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	PEU_CERT_OWNER_INFO	pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUReadAndRecoverPrivateKeyBinary(
	unsigned char*			pbPrivateKey,
	unsigned long			dwPrivateKeyLength,
	char*			pszPassword,
	PEU_CERT_OWNER_INFO	pInfo);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SSERVER_CLIENT_SIGN_HASH)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszHashDescription,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				pszSignAlgorithmName,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSServerClientSignHash(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszHashDescription,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				pszSignAlgorithmName,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_SSERVER_CLIENT_SIGN_FILE)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszSignAlgorithmName,
	char*				pszFileName,
	char*				pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSServerClientSignFile(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszSignAlgorithmName,
	char*				pszFileName,
	char*				pszFileNameWithSign);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SSERVER_CLIENT_GENERATE_PRIVATE_KEY)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszPrivateKeyDescription,
	char*				pszUAAlgorithmName,
	unsigned long				dwUADSKeyLength,
	int				bUseDSKeyAsKEP,
	unsigned long				dwUAKEPKeyLength,
	char*				pszInternationalAlgorithmName,
	unsigned long				dwInternationalKeyLength,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSServerClientGeneratePrivateKey(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszPrivateKeyDescription,
	char*				pszUAAlgorithmName,
	unsigned long				dwUADSKeyLength,
	int				bUseDSKeyAsKEP,
	unsigned long				dwUAKEPKeyLength,
	char*				pszInternationalAlgorithmName,
	unsigned long				dwInternationalKeyLength,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SIGN_HASH_RSA)(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignHashRSA(
	char*			pszHash,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_SIGNER)(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetSigner(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_FILE_SIGNER)(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileSigner(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_APPEND_VALIDATION_DATA_TO_SIGNER)(
	char*			pszPreviousSigner,
	unsigned char*			pbPreviousSigner,
	unsigned long			dwPreviousSignerLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendValidationDataToSigner(
	char*			pszPreviousSigner,
	unsigned char*			pbPreviousSigner,
	unsigned long			dwPreviousSignerLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_HOST_INFO)(
	char*			*ppszHostInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetHostInfo(
	char*			*ppszHostInfo);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_IS_REMOTELY_CONTROLLED)(
	int*			pbIsRemotelyControlled);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUIsRemotelyControlled(
	int*			pbIsRemotelyControlled);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SSERVER_CLIENT_SIGN_HASH_ASYNC)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszHashDescription,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				pszSignAlgorithmName,
	char*				*ppszOperationID);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSServerClientSignHashAsync(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszHashDescription,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	char*				pszSignAlgorithmName,
	char*				*ppszOperationID);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_SSERVER_CLIENT_CHECK_SIGN_HASH_STATUS)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSServerClientCheckSignHashStatus(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID,
	char*				*ppszSign,
	unsigned char*				*ppbSign,
	unsigned long*				pdwSignLength);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_SSERVER_CLIENT_GENERATE_PRIVATE_KEY_ASYNC)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszPrivateKeyDescription,
	char*				pszUAAlgorithmName,
	unsigned long				dwUADSKeyLength,
	int				bUseDSKeyAsKEP,
	unsigned long				dwUAKEPKeyLength,
	char*				pszInternationalAlgorithmName,
	unsigned long				dwInternationalKeyLength,
	char*				*ppszOperationID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSServerClientGeneratePrivateKeyAsync(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszPrivateKeyDescription,
	char*				pszUAAlgorithmName,
	unsigned long				dwUADSKeyLength,
	int				bUseDSKeyAsKEP,
	unsigned long				dwUAKEPKeyLength,
	char*				pszInternationalAlgorithmName,
	unsigned long				dwInternationalKeyLength,
	char*				*ppszOperationID);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_SSERVER_CLIENT_CHECK_GENERATE_PRIVATE_KEY_STATUS)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSServerClientCheckGeneratePrivateKeyStatus(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ADD_PAYMENT)(
	unsigned long				dwPaymentType,
	PSYSTEMTIME			pstPaymentTime,
	char*				pszPaymentID,
	unsigned long				dwEUPayerSN,
	unsigned char*				pbEUPayerCert,
	unsigned long				dwEUPayerCertLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAddPayment(
	unsigned long				dwPaymentType,
	PSYSTEMTIME			pstPaymentTime,
	char*				pszPaymentID,
	unsigned long				dwEUPayerSN,
	unsigned char*				pbEUPayerCert,
	unsigned long				dwEUPayerCertLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_MAKE_NEW_OWN_CERTIFICATE)(
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUMakeNewOwnCertificate(
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef void (*PEU_FREE_EUSER_PARAMS)(
	PEU_USER_PARAMS		pEUserParams);
#ifdef PC_STATIC_LIBS
extern "C"
void EUFreeEUserParams(
	PEU_USER_PARAMS		pEUserParams);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_GET_OWN_EUSER_PARAMS)(
	PEU_USER_PARAMS		*ppEUserParams);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetOwnEUserParams(
	PEU_USER_PARAMS		*ppEUserParams);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_MODIFY_OWN_EUSER_PARAMS)(
	char*				pszPhone,
	char*				pszEMail);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUModifyOwnEUserParams(
	char*				pszPhone,
	char*				pszEMail);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef void (*PEU_CTX_FREE_EUSER_PARAMS)(
	void*				pvContext,
	PEU_USER_PARAMS		pEUserParams);
#ifdef PC_STATIC_LIBS
extern "C"
void EUCtxFreeEUserParams(
	void*				pvContext,
	PEU_USER_PARAMS		pEUserParams);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_GET_OWN_EUSER_PARAMS)(
	void*				pvPrivateKeyContext,
	PEU_USER_PARAMS		*ppEUserParams);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxGetOwnEUserParams(
	void*				pvPrivateKeyContext,
	PEU_USER_PARAMS		*ppEUserParams);
#endif //PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_CTX_MODIFY_OWN_EUSER_PARAMS)(
	void*				pvPrivateKeyContext,
	char*				pszPhone,
	char*				pszEMail);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxModifyOwnEUserParams(
	void*				pvPrivateKeyContext,
	char*				pszPhone,
	char*				pszEMail);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_RAW_SIGN_DATA)(
	void*			pvPrivateKeyContext,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxRawSignData(
	void*			pvPrivateKeyContext,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_RAW_SIGN_HASH)(
	void*			pvPrivateKeyContext,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxRawSignHash(
	void*			pvPrivateKeyContext,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_CERTIFICATE_BY_KEY_INFO_WITH_SETTINGS)(
	unsigned long				dwTypeIndex,
	unsigned long				dwDevIndex,
	unsigned char*				pbPrivKeyInfo,
	unsigned long				dwPrivKeyInfo,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	int				bSilentMode,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetCertificateByKeyInfoWithSettings(
	unsigned long				dwTypeIndex,
	unsigned long				dwDevIndex,
	unsigned char*				pbPrivKeyInfo,
	unsigned long				dwPrivKeyInfo,
	unsigned long				dwCertKeyType,
	unsigned long				dwKeyUsage,
	int				bSilentMode,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertificateLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_ENVELOP_DATA_WITH_DYNAMIC_KEY)(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnvelopDataWithDynamicKey(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ENVELOP_FILE_WITH_DYNAMIC_KEY)(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	char*				pszFileName,
	char*				pszEnvelopedFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnvelopFileWithDynamicKey(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bSignData,
	int				bAppendCert,
	char*				pszFileName,
	char*				pszEnvelopedFileName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_CREATE_EMPTY_SIGN_FILE)(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	char*				pszFileName,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxCreateEmptySignFile(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	char*				pszFileName,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileNameWithSign);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_APPEND_SIGNER_FILE)(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbSigner,
	unsigned long				dwSignerLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileNameWithPreviousSign,
	char*				pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxAppendSignerFile(
	void*				pvContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbSigner,
	unsigned long				dwSignerLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileNameWithPreviousSign,
	char*				pszFileNameWithSign);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_MAKE_NEW_OWN_CERTIFICATE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxMakeNewOwnCertificate(
	void*				pvPrivateKeyContext,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SIGN_DATA_ECDSA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bAppendCert,
	int			bExternalSign,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSignDataECDSA(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bAppendCert,
	int			bExternalSign,
	char*			*ppszSignedData,
	unsigned char*			*ppbSignedData,
	unsigned long*			pdwSignedDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_HMAC_DATA_SHA)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbKey,
	unsigned long				dwKeyLength,
	char*				*ppszHash,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetHMACDataSHA(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbKey,
	unsigned long				dwKeyLength,
	char*				*ppszHash,
	unsigned char*				*ppbHash,
	unsigned long*				pdwHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CHECK_HMAC_DATA_SHA)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbKey,
	unsigned long				dwKeyLength,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCheckHMACDataSHA(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbKey,
	unsigned long				dwKeyLength,
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_MAKE_NEW_NAMED_CERTIFICATE)(
	void*				pvContext,
	PEU_KEY_MEDIA		pOldKeyMedia,
	char*				pszOldNamedPrivateKeyLabel,
	char*				pszOldNamedPrivateKeyPassword,
	unsigned char*				pbOldPrivateKey,
	unsigned long				dwOldPrivateKeyLength,
	char*				pszOldPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_KEY_MEDIA		pNewKeyMedia,
	char*				pszNewNamedPrivateKeyLabel,
	char*				pszNewNamedPrivateKeyPassword,
	char*				pszNewPrivateKeyPassword,
	unsigned char*				*ppbNewPrivateKey,
	unsigned long*				pdwNewPrivateKeyLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxMakeNewNamedCertificate(
	void*				pvContext,
	PEU_KEY_MEDIA		pOldKeyMedia,
	char*				pszOldNamedPrivateKeyLabel,
	char*				pszOldNamedPrivateKeyPassword,
	unsigned char*				pbOldPrivateKey,
	unsigned long				dwOldPrivateKeyLength,
	char*				pszOldPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	int				bUseUADSKeyAsKEP,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_KEY_MEDIA		pNewKeyMedia,
	char*				pszNewNamedPrivateKeyLabel,
	char*				pszNewNamedPrivateKeyPassword,
	char*				pszNewPrivateKeyPassword,
	unsigned char*				*ppbNewPrivateKey,
	unsigned long*				pdwNewPrivateKeyLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_CERTIFICATES)(
	unsigned char*		*ppbCertificates,
	unsigned long*		pdwCertificatesLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetCertificates(
	unsigned char*		*ppbCertificates,
	unsigned long*		pdwCertificatesLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SAVE_CERTIFICATES_EX)(
	unsigned char*		pbCertificates,
	unsigned long		dwCertificatesLength,
	unsigned char*		pbTrustedCertificates,
	unsigned long		dwTrustedCertificatesLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSaveCertificatesEx(
	unsigned char*		pbCertificates,
	unsigned long		dwCertificatesLength,
	unsigned char*		pbTrustedCertificates,
	unsigned long		dwTrustedCertificatesLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_SIGN_TYPE)(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	unsigned long*			pdwSignType);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetSignType(
	unsigned long			dwSignIndex,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	unsigned long*			pdwSignType);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_FILE_SIGN_TYPE)(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	unsigned long*			pdwSignType);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetFileSignType(
	unsigned long			dwSignIndex,
	char*			pszFileNameWithSign,
	unsigned long*			pdwSignType);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_OPEN_PRIVATE_KEY)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	void*				*ppvPrivKeyContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxOpenPrivateKey(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	void*				*ppvPrivKeyContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_PREPARE_NAMED_PRIVATE_KEY)(
	void*				pvPrivateKeyContext,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxPrepareNamedPrivateKey(
	void*				pvPrivateKeyContext,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_GENERATE_NAMED_PRIVATE_KEY_EX)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGenerateNamedPrivateKeyEx(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwInternationalKeysSpec,
	char*				pszInternationalParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbInternationalRequest,
	unsigned long*				pdwInternationalRequest,
	char*				pszInternationalReqFileName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_APPEND_VALIDATION_DATA_TO_SIGNER_EX)(
	char*			pszPreviousSigner,
	unsigned char*			pbPreviousSigner,
	unsigned long			dwPreviousSignerLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned long			dwSignType,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendValidationDataToSignerEx(
	char*			pszPreviousSigner,
	unsigned char*			pbPreviousSigner,
	unsigned long			dwPreviousSignerLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned long			dwSignType,
	char*			*ppszSigner,
	unsigned char*			*ppbSigner,
	unsigned long*			pdwSignerLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SSERVER_CLIENT_SIGN_HASHES_ASYNC)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszOperationDescription,
	char*				pszHashesDescription,
	char*				pszHashes,
	unsigned long				dwHashes,
	unsigned char*				*ppbHashes,
	unsigned long*				pdwHashesLength,
	char*				pszSignAlgorithmName,
	char*				*ppszOperationID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSServerClientSignHashesAsync(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOriginatorDescription,
	char*				pszOperationDescription,
	char*				pszHashesDescription,
	char*				pszHashes,
	unsigned long				dwHashes,
	unsigned char*				*ppbHashes,
	unsigned long*				pdwHashesLength,
	char*				pszSignAlgorithmName,
	char*				*ppszOperationID);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SSERVER_CLIENT_CHECK_SIGN_HASHES_STATUS)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID,
	PPEU_SS_SIGN_HASH_RESULT
						*pppSignResults,
	unsigned long*				pdwResults);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSServerClientCheckSignHashesStatus(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID,
	PPEU_SS_SIGN_HASH_RESULT
						*pppSignResults,
	unsigned long*				pdwResults);
#endif //PC_STATIC_LIBS

typedef void (*PEU_SSERVER_CLIENT_FREE_SIGN_HASHES_RESULTS)(
	PPEU_SS_SIGN_HASH_RESULT
						ppSignResults,
	unsigned long				dwResults);
#ifdef PC_STATIC_LIBS
extern "C" void EUSServerClientFreeSignHashesResults(
	PPEU_SS_SIGN_HASH_RESULT
						ppSignResults,
	unsigned long				dwResults);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_CREATE_AUTH_DATA)(
	void*				pvPrivateKeyContext,
	unsigned char*				pbServerCertificate,
	unsigned long				dwServerCertificateLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbAuthData,
	unsigned long*				pdwAuthDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxCreateAuthData(
	void*				pvPrivateKeyContext,
	unsigned char*				pbServerCertificate,
	unsigned long				dwServerCertificateLength,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbAuthData,
	unsigned long*				pdwAuthDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_CHECK_AUTH_DATA)(
	void*				pvPrivateKeyContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbAuthData,
	unsigned long				dwAuthDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxCheckAuthData(
	void*				pvPrivateKeyContext,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				pbAuthData,
	unsigned long				dwAuthDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_APPEND_RECIPIENT)(
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	char*			pszRecipient,
	unsigned char*			pbRecipient,
	unsigned long			dwRecipientLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUAppendRecipient(
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	char*			pszRecipient,
	unsigned char*			pbRecipient,
	unsigned long			dwRecipientLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_RECIPIENT)(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			*ppszRecipient,
	unsigned char*			*ppbRecipient,
	unsigned long*			pdwRecipientLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetRecipient(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			*ppszRecipient,
	unsigned char*			*ppbRecipient,
	unsigned long*			pdwRecipientLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_REMOVE_RECIPIENT)(
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EURemoveRecipient(
	char*			pszPreviousEnvelopedData,
	unsigned char*			pbPreviousEnvelopedData,
	unsigned long			dwPreviousEnvelopedDataLength,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_PASSWORD_RECIPIENT_DEVELOP_DATA)(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	char*			pszPasswordRecipient,
	unsigned char*			pbPasswordRecipient,
	unsigned long			dwPasswordRecipientLength,
	char*			pszPassword,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUPasswordRecipientDevelopData(
	char*			pszEnvelopedData,
	unsigned char*			pbEnvelopedData,
	unsigned long			dwEnvelopedDataLength,
	char*			pszPasswordRecipient,
	unsigned char*			pbPasswordRecipient,
	unsigned long			dwPasswordRecipientLength,
	char*			pszPassword,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	PEU_ENVELOP_INFO
					pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_MAKE_PASSWORD_RECIPIENT)(
	void*			pvPrivateKeyContext,
	unsigned char*			pbRecipient,
	unsigned long			dwRecipientLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertLength,
	const char*			pszPassword,
	unsigned char*			*ppbPasswordRecipient,
	unsigned long*			pdwPasswordRecipientLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxMakePasswordRecipient(
	void*			pvPrivateKeyContext,
	unsigned char*			pbRecipient,
	unsigned long			dwRecipientLength,
	unsigned char*			pbSenderCert,
	unsigned long			dwSenderCertLength,
	const char*			pszPassword,
	unsigned char*			*ppbPasswordRecipient,
	unsigned long*			pdwPasswordRecipientLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_MAKE_OTHER_RECIPIENT)(
	void*			pvPrivateKeyContext,
	unsigned char*			pbRecipient,
	unsigned long			dwRecipientLength,
	unsigned char*			pbOtherRecipientCert,
	unsigned long			dwOtherRecipientCertLength,
	unsigned char*			*ppbOtherRecipient,
	unsigned long*			pdwOtherRecipientLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxMakeOtherRecipient(
	void*			pvPrivateKeyContext,
	unsigned char*			pbRecipient,
	unsigned long			dwRecipientLength,
	unsigned char*			pbOtherRecipientCert,
	unsigned long			dwOtherRecipientCertLength,
	unsigned char*			*ppbOtherRecipient,
	unsigned long*			pdwOtherRecipientLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_PARSE_CERTIFICATE_EX)(
	void*			pvContext,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	PPEU_CERT_INFO_EX	
					ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxParseCertificateEx(
	void*			pvContext,
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	PPEU_CERT_INFO_EX	
					ppInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GET_CR_INFO)(
	void*			pvContext,
	unsigned char*			pbRequest,
	unsigned long			dwRequest,
	PEU_CR_INFO		*ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGetCRInfo(
	void*			pvContext,
	unsigned char*			pbRequest,
	unsigned long			dwRequest,
	PEU_CR_INFO		*ppInfo);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CTX_FREE_CR_INFO)(
	void*			pvContext,
	PEU_CR_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeCRInfo(
	void*			pvContext,
	PEU_CR_INFO		pInfo);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_MAKE_DEVICE_CERTIFICATE)(
	void*			pvPrivateKeyContext,
	char*			pszDeviceName,
	unsigned char*			pbUARequest,
	unsigned long			dwUARequestLength,
	unsigned char*			pbUAKEPRequest,
	unsigned long			dwUAKEPRequestLength,
	unsigned char*			pbInternationalRequest,
	unsigned long			dwInternationalRequestLength,
	unsigned char*			pbECDSARequest,
	unsigned long			dwECDSARequestLength,
	char*			pszCMPAddress,
	char*			pszCMPPort,
	unsigned char*			*ppbUACertificate,
	unsigned long*			pdwUACertificateLength,
	unsigned char*			*ppbUAKEPCertificate,
	unsigned long*			pdwUAKEPCertificateLength,
	unsigned char*			*ppbInternationalCertificate,
	unsigned long*			pdwInternationalCertificateLength,
	unsigned char*			*ppbECDSACertificate,
	unsigned long*			pdwECDSACertificateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxMakeDeviceCertificate(
	void*			pvPrivateKeyContext,
	char*			pszDeviceName,
	unsigned char*			pbUARequest,
	unsigned long			dwUARequestLength,
	unsigned char*			pbUAKEPRequest,
	unsigned long			dwUAKEPRequestLength,
	unsigned char*			pbInternationalRequest,
	unsigned long			dwInternationalRequestLength,
	unsigned char*			pbECDSARequest,
	unsigned long			dwECDSARequestLength,
	char*			pszCMPAddress,
	char*			pszCMPPort,
	unsigned char*			*ppbUACertificate,
	unsigned long*			pdwUACertificateLength,
	unsigned char*			*ppbUAKEPCertificate,
	unsigned long*			pdwUAKEPCertificateLength,
	unsigned char*			*ppbInternationalCertificate,
	unsigned long*			pdwInternationalCertificateLength,
	unsigned char*			*ppbECDSACertificate,
	unsigned long*			pdwECDSACertificateLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_OPEN_IDCARD_VIRTUAL)(
	const char*			pszTypeDescription,
	void*			*ppvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxOpenIDCardVirtual(
	const char*			pszTypeDescription,
	void*			*ppvDeviceContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_AA_CREDENTIALS)(
	void*			pvDeviceContext,
	unsigned char*			pbNonce,
	unsigned long			dwNonceLength,
	unsigned char*			*ppbSignature,
	unsigned long*			pdwSignatureLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGetIDCardAACredentials(
	void*			pvDeviceContext,
	unsigned char*			pbNonce,
	unsigned long			dwNonceLength,
	unsigned char*			*ppbSignature,
	unsigned long*			pdwSignatureLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_VERIFY_IDCARD_AA_CREDENTIALS)(
	void*			pvDeviceContext,
	unsigned char*			pbNonce,
	unsigned long			dwNonceLength,
	unsigned char*			pbPublicKeyInfo,
	unsigned long			dwPublicKeyInfoLength,
	unsigned char*			pbSignature,
	unsigned long			dwSignatureLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxVerifyIDCardAACredentials(
	void*			pvDeviceContext,
	unsigned char*			pbNonce,
	unsigned long			dwNonceLength,
	unsigned char*			pbPublicKeyInfo,
	unsigned long			dwPublicKeyInfoLength,
	unsigned char*			pbSignature,
	unsigned long			dwSignatureLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_ENUM_IDCARD_SIGNED_DATA)(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned long			dwIndex,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	unsigned char*			*ppbSignature,
	unsigned long*			pdwSignatureLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxEnumIDCardSignedData(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned long			dwIndex,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength,
	unsigned char*			*ppbSignature,
	unsigned long*			pdwSignatureLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_VALIDATE_IDCARD_DATA_GROUP)(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	unsigned char*			pbSOD,
	unsigned long			dwSODLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxValidateIDCardDataGroup(
	void*			pvDeviceContext,
	unsigned char			bTag,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	unsigned char*			pbSOD,
	unsigned long			dwSODLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_VERIFY_IDCARD_SECURITY_OBJECT_DOCUMENT_DATA)(
	void*			pvDeviceContext,
	unsigned char*			pbSOD,
	unsigned long			dwSODLength,
	char*			pszCertificatesStorePath);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxVerifyIDCardSecurityObjectDocumentData(
	void*			pvDeviceContext,
	unsigned char*			pbSOD,
	unsigned long			dwSODLength,
	char*			pszCertificatesStorePath);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_BASIC_USER_INFO)(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszSurname,
	char*			pszName,
	PSYSTEMTIME		pstDateOfBirth,
	char*			pszUNZR);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGetIDCardBasicUserInfo(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszSurname,
	char*			pszName,
	PSYSTEMTIME		pstDateOfBirth,
	char*			pszUNZR);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_BASIC_INFO)(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszDocumentNumber,
	PSYSTEMTIME		pstExpirationDate);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGetIDCardBasicInfo(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszDocumentNumber,
	PSYSTEMTIME		pstExpirationDate);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_USER_FULL_NAME)(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszSurname,
	char*			pszName,
	char*			pszGivenname);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGetIDCardUserFullName(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszSurname,
	char*			pszName,
	char*			pszGivenname);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_USER_DRFO_CODE)(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszDRFOCode);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGetIDCardUserDRFOCode(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszDRFOCode);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_ADDITIONAL_INFO)(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszIssuer,
	PSYSTEMTIME		pstDateOfIssue);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGetIDCardAdditionalInfo(
	void*			pvDeviceContext,
	unsigned char*			pbDataGroup,
	unsigned long			dwDataGroupLength,
	char*			pszIssuer,
	PSYSTEMTIME		pstDateOfIssue);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef void (*PEU_CTX_FREE_COUPLE_SIGN)(
	void*			pvSignContext);
#ifdef PC_STATIC_LIBS
extern "C" void EUCtxFreeCoupleSign(
	void*			pvSignContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_CLIENT_CREATE_COUPLE_SIGN_STEP1)(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength,
	void*			*ppvSignContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxClientCreateCoupleSignStep1(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength,
	void*			*ppvSignContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_SERVER_CREATE_COUPLE_SIGN_STEP1)(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength,
	void*			*ppvSignContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxServerCreateCoupleSignStep1(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned char*			pbHash,
	unsigned long			dwHashLength,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength,
	void*			*ppvSignContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_CLIENT_CREATE_COUPLE_SIGN_STEP2)(
	void*			pvSignContext,
	unsigned char*			pbServerData,
	unsigned long			dwServerDataLength,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxClientCreateCoupleSignStep2(
	void*			pvSignContext,
	unsigned char*			pbServerData,
	unsigned long			dwServerDataLength,
	unsigned char*			*ppbClientData,
	unsigned long*			pdwClientDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_SERVER_CREATE_COUPLE_SIGN_STEP2)(
	void*			pvSignContext,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	unsigned char*			*ppbSignValue,
	unsigned long*			pdwSignValueLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxServerCreateCoupleSignStep2(
	void*			pvSignContext,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	unsigned char*			*ppbSignValue,
	unsigned long*			pdwSignValueLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_SERVER_CREATE_COUPLE_CR_BEGIN)(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned long			dwHashAlgo,
	unsigned char*			pbClientRequest,
	unsigned long			dwClientRequestLength,
	unsigned char*			*ppbRequest,
	unsigned long*			pdwRequestLength,
	unsigned char*			*ppbAttrsHash,
	unsigned long*			pdwAttrsHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxServerCreateCoupleCRBegin(
	void*			pvPrivateKeyContext,
	unsigned long			dwSignAlgo,
	unsigned long			dwHashAlgo,
	unsigned char*			pbClientRequest,
	unsigned long			dwClientRequestLength,
	unsigned char*			*ppbRequest,
	unsigned long*			pdwRequestLength,
	unsigned char*			*ppbAttrsHash,
	unsigned long*			pdwAttrsHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CREATE_COUPLE_CR_BEGIN)(
	unsigned char*			pbClientRequest,
	unsigned long			dwClientRequestLength,
	unsigned char*			pbServerRequest,
	unsigned long			dwServerRequestLength,
	unsigned char*			*ppbRequest,
	unsigned long*			pdwRequestLength,
	unsigned char*			*ppbAttrsHash,
	unsigned long*			pdwAttrsHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateCoupleCRBegin(
	unsigned char*			pbClientRequest,
	unsigned long			dwClientRequestLength,
	unsigned char*			pbServerRequest,
	unsigned long			dwServerRequestLength,
	unsigned char*			*ppbRequest,
	unsigned long*			pdwRequestLength,
	unsigned char*			*ppbAttrsHash,
	unsigned long*			pdwAttrsHashLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CREATE_CR_END)(
	unsigned char*			pbUnsignedRequest,
	unsigned long			dwUnsignedRequestLength,
	unsigned char*			pbSignarure,
	unsigned long			dwSignatureLength,
	unsigned char*			*ppbRequest,
	unsigned long*			pdwRequestLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateCREnd(
	unsigned char*			pbUnsignedRequest,
	unsigned long			dwUnsignedRequestLength,
	unsigned char*			pbSignarure,
	unsigned long			dwSignatureLength,
	unsigned char*			*ppbRequest,
	unsigned long*			pdwRequestLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CREATE_SIGNER_EX)(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bNoContentTimeStamp,
	unsigned long				dwSignType,
	char*				*ppszSigner,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateSignerEx(
	char*				pszHash,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bNoContentTimeStamp,
	unsigned long				dwSignType,
	char*				*ppszSigner,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_CREATE_SIGNER_EX)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bNoContentTimeStamp,
	unsigned long				dwSignType,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxCreateSignerEx(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bNoContentTimeStamp,
	unsigned long				dwSignType,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_VERIFY_SECURITY_OBJECT_DOCUMENT_ERROR)(
	void*			pvDeviceContext,
	char*			pszLastVerifySODError);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGetIDCardLastVerifySecurityObjectDocumentError(
	void*			pvDeviceContext,
	char*			pszLastVerifySODError);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GENERATE_PRIVATE_KEY_2)(
	PEU_KEY_MEDIA		pKeyMedia,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwRSAKeysSpec,
	char*				pszRSAParamsPath,
	unsigned long				dwECDSAKeysSpec,
	char*				pszECDSAParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbPrivKey,
	unsigned long*				pdwPrivKey,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfo,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbRSARequest,
	unsigned long*				pdwRSARequest,
	char*				pszRSAReqFileName,
	unsigned char*				*ppbECDSARequest,
	unsigned long*				pdwECDSARequest,
	char*				pszECDSAReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGeneratePrivateKey2(
	PEU_KEY_MEDIA		pKeyMedia,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwRSAKeysSpec,
	char*				pszRSAParamsPath,
	unsigned long				dwECDSAKeysSpec,
	char*				pszECDSAParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbPrivKey,
	unsigned long*				pdwPrivKey,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfo,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbRSARequest,
	unsigned long*				pdwRSARequest,
	char*				pszRSAReqFileName,
	unsigned char*				*ppbECDSARequest,
	unsigned long*				pdwECDSARequest,
	char*				pszECDSAReqFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_GENERATE_NAMED_PRIVATE_KEY_2)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwRSAKeysSpec,
	char*				pszRSAParamsPath,
	unsigned long				dwECDSAKeysSpec,
	char*				pszECDSAParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbRSARequest,
	unsigned long*				pdwRSARequest,
	char*				pszRSAReqFileName,
	unsigned char*				*ppbECDSARequest,
	unsigned long*				pdwECDSARequest,
	char*				pszECDSAReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGenerateNamedPrivateKey2(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwRSAKeysSpec,
	char*				pszRSAParamsPath,
	unsigned long				dwECDSAKeysSpec,
	char*				pszECDSAParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbRSARequest,
	unsigned long*				pdwRSARequest,
	char*				pszRSAReqFileName,
	unsigned char*				*ppbECDSARequest,
	unsigned long*				pdwECDSARequest,
	char*				pszECDSAReqFileName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_OPEN_IDCARD_EX)(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	unsigned long			dwPasswordType,
	unsigned long			dwPasswordVersion,
	unsigned long			dwTerminalType,
	void*			*ppvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxOpenIDCardEx(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	unsigned long			dwPasswordType,
	unsigned long			dwPasswordVersion,
	unsigned long			dwTerminalType,
	void*			*ppvDeviceContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_ACTIVATE_IDCARD_ESIGN)(
	void*				pvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxActivateIDCardESign(
	void*				pvDeviceContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_VERSION)(
	void*				pvDeviceContext,
	unsigned long*				pdwVersion);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxGetIDCardVersion(
	void*				pvDeviceContext,
	unsigned long*				pdwVersion);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_DEV_CTX_GET_IDCARD_VERSION_FROM_DEVICE)(
	const char*				pszTypeDescription,
	const char*				pszDeviceDescription,
	unsigned long*				pdwVersion);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxGetIDCardVersionFromDevice(
	const char*				pszTypeDescription,
	const char*				pszDeviceDescription,
	unsigned long*				pdwVersion);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ASIC_GET_ASIC_TYPE)(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwASiCType);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetASiCType(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwASiCType);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_GET_SIGN_TYPE)(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwSignType);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetSignType(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwSignType);
#endif //PC_STATIC_LIBS	

typedef unsigned long (*PEU_ASIC_GET_SINGS_COUNT)(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwSignsCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetSignsCount(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwSignsCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_GET_SIGNER_INFO)(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetSignerInfo(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength); 
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_GET_SIGN_TIME_INFO)(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PPEU_TIME_INFO		ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetSignTimeInfo(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PPEU_TIME_INFO		ppInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_GET_SIGN_REFERENCES)(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	char*				*ppszReferences);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetSignReferences(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	char*				*ppszReferences);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_GET_REFERENCE)(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	char*				pszReference,
	unsigned char*				*ppbReference,
	unsigned long*				pdwReferenceLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetReference(
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	char*				pszReference,
	unsigned char*				*ppbReference,
	unsigned long*				pdwReferenceLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_SIGN_DATA)(
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCSignData(
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_VERIFY_DATA)(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PEU_SIGN_INFO		pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCVerifyData(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PEU_SIGN_INFO		pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ASIC_SIGN_DATA)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxASiCSignData(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ASIC_GET_SIGNER_INFO)(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxASiCGetSignerInfo(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength); 
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ASIC_GET_SIGN_LEVEL)(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwSignLevel);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCGetSignLevel(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	unsigned long*				pdwSignLevel);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_PDF_GET_SIGN_TYPE)(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	unsigned long*				pdwType);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUPDFGetSignType(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	unsigned long*				pdwType);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_PDF_GET_SINGS_COUNT)(
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	unsigned long*				pdwSignsCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUPDFGetSignsCount(
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	unsigned long*				pdwSignsCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_PDF_GET_SIGNER_INFO)(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUPDFGetSignerInfo(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength); 
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_PDF_GET_SIGNER_INFO)(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxPDFGetSignerInfo(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength); 
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_PDF_GET_SIGN_TIME_INFO)(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	PPEU_TIME_INFO		ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUPDFGetSignTimeInfo(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	PPEU_TIME_INFO		ppInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_PDF_SIGN_DATA)(
	unsigned char*				pbPDFData,
	unsigned long				dwPDFDataLength,
	unsigned long				dwSignType,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUPDFSignData(
	unsigned char*				pbPDFData,
	unsigned long				dwPDFDataLength,
	unsigned long				dwSignType,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_PDF_VERIFY_DATA)(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwSignedPDFDataLength,
	PEU_SIGN_INFO		pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUPDFVerifyData(
	unsigned long				dwSignIndex,
	unsigned char*				pbSignedPDFData,
	unsigned long				dwPDFDataLength,
	PEU_SIGN_INFO		pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_PDF_SIGN_DATA)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbPDFData,
	unsigned long				dwPDFDataLength,
	unsigned long				dwSignType,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxPDFSignData(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned char*				pbPDFData,
	unsigned long				dwPDFDataLength,
	unsigned long				dwSignType,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_COSE_SIGN_DATA)(
	unsigned long				dwHashAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbSignedData,
	unsigned long*				pdwSignedDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCOSESignData(
	unsigned long				dwHashAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbSignedData,
	unsigned long*				pdwSignedDataLength);
#endif // PC_STATIC_LIBS

typedef unsigned long (*PEU_COSE_SIGN_FILE)(
	unsigned long				dwHashAlgo,
	char*				pszFileName,
	char*				pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCOSESignFile(
	unsigned long				dwHashAlgo,
	char*				pszFileName,
	char*				pszFileNameWithSign);
#endif // PC_STATIC_LIBS

typedef unsigned long (*PEU_COSE_VERIFY_DATA)(
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCOSEVerifyData(
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_COSE_VERIFY_FILE)(
	char*				pszFileNameWithSign,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileName,
	PEU_SIGN_INFO		pInfo);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCOSEVerifyFile(
	char*				pszFileNameWithSign,
	unsigned char*				pbCertificate,
	unsigned long				dwCertificateLength,
	char*				pszFileName,
	PEU_SIGN_INFO		pInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_COSE_GET_KEY_ID_FROM_SIGNED_DATA)(
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	char*				*ppszCOSEKeyID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCOSEGetKeyIDFromSignedData(
	unsigned char*				pbSignedData,
	unsigned long				dwSignedDataLength,
	char*				*ppszCOSEKeyID);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_COSE_GET_KEY_ID_FROM_SIGNED_FILE)(
	char*				pszFileNameWithSign,
	char*				*ppszCOSEKeyID);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCOSEGetKeyIDFromSignedFile(
	char*				pszFileNameWithSign,
	char*				*ppszCOSEKeyID);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_COSE_SIGN_DATA)(
	void*				pvPrivateKeyContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbSignedData,
	unsigned long*				pdwSignedDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxCOSESignData(
	void*				pvPrivateKeyContext,
	unsigned long				dwHashAlgo,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbSignedData,
	unsigned long*				pdwSignedDataLength);
#endif // PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_COSE_SIGN_FILE)(
	void*				pvPrivateKeyContext,
	unsigned long				dwHashAlgo,
	char*				pszFileName,
	char*				pszFileNameWithSign);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxCOSESignFile(
	void*				pvPrivateKeyContext,
	unsigned long				dwHashAlgo,
	char*				pszFileName,
	char*				pszFileNameWithSign);
#endif // PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_BASE45_ENCODE)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszData);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUBASE45Encode(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			*ppszData);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_BASE45_DECODE)(
	char*			pszData,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUBASE45Decode(
	char*			pszData,
	unsigned char*			*ppbData,
	unsigned long*			pdwDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_COMPRESS_DATA)(
	unsigned long				dwCompressionLevel,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbCompressedData,
	unsigned long*				pdwCompressedDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCompressData(
	unsigned long				dwCompressionLevel,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbCompressedData,
	unsigned long*				pdwCompressedDataLength);
#endif // PC_STATIC_LIBS

typedef unsigned long (*PEU_UNCOMPRESS_DATA)(
	unsigned char*				pbCompressedData,
	unsigned long				dwCompressedDataLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUUncompressData(
	unsigned char*				pbCompressedData,
	unsigned long				dwCompressedDataLength,
	unsigned char*				*ppbData,
	unsigned long*				pdwDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_COMPRESS_FILE)(
	unsigned long				dwCompressionLevel,
	char*				pszFileName,
	char*				pszCompressedFileName);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCompressFile(
	unsigned long				dwCompressionLevel,
	char*				pszFileName,
	char*				pszCompressedFileName);
#endif // PC_STATIC_LIBS

typedef unsigned long (*PEU_UNCOMPRESS_FILE)(
	char*				pszCompressedFileName,
	char*				pszFileName);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUUncompressFile(
	char*				pszCompressedFileName,
	char*				pszFileName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ASIC_IS_ALL_CONTENT_COVERED)(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	int*				pbCovered);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCIsAllContentCovered(
	unsigned long				dwSignIndex,
	unsigned char*				pbASiCData,
	unsigned long				dwASiCDataLength,
	int*				pbCovered);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_XADES_GET_TYPE)(
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	unsigned long*				pdwSignType);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESGetType(
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	unsigned long*				pdwSignType);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_GET_SINGS_COUNT)(
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	unsigned long*				pdwSignsCount);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESGetSignsCount(
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	unsigned long*				pdwSignsCount);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_GET_SIGN_LEVEL)(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	unsigned long*				pdwSignLevel);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESGetSignLevel(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	unsigned long*				pdwSignLevel);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_GET_SIGNER_INFO)(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESGetSignerInfo(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength); 
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_GET_SIGN_TIME_INFO)(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PPEU_TIME_INFO		ppInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESGetSignTimeInfo(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PPEU_TIME_INFO		ppInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_GET_SIGN_REFERENCES)(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	char*				*ppszReferences);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESGetSignReferences(
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	char*				*ppszReferences);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_GET_REFERENCE)(
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	char*				pszReference,
	unsigned char*				*ppbReference,
	unsigned long*				pdwReferenceLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESGetReference(
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	char*				pszReference,
	unsigned char*				*ppbReference,
	unsigned long*				pdwReferenceLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_SIGN_DATA)(
	unsigned long				dwXAdESType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbXAdESData,
	unsigned long*				pdwXAdESDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESSignData(
	unsigned long				dwXAdESType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbXAdESData,
	unsigned long*				pdwXAdESDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_XADES_VERIFY_DATA)(
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PEU_SIGN_INFO		pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUXAdESVerifyData(
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PEU_SIGN_INFO		pSignInfo);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_XADES_SIGN_DATA)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned long				dwXAdESType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbXAdESData,
	unsigned long*				pdwXAdESDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxXAdESSignData(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned long				dwXAdESType,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbXAdESData,
	unsigned long*				pdwXAdESDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_XADES_GET_SIGNER_INFO)(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxXAdESGetSignerInfo(
	void*				pvContext,
	unsigned long				dwSignIndex,
	unsigned char*				pbXAdESData,
	unsigned long				dwXAdESDataLength,
	PPEU_CERT_INFO_EX	ppInfo,
	unsigned char*				*ppbCertificate,
	unsigned long*				pdwCertifiacateLength); 
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_MAC_DATA)(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				pszPassword,
	char*				*ppszMAC,
	unsigned char*				*ppbMAC,
	unsigned long*				pdwMACLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetMACData(
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	char*				pszPassword,
	char*				*ppszMAC,
	unsigned char*				*ppbMAC,
	unsigned long*				pdwMACLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_GENERATE_NAMED_PRIVATE_KEY_2_EX)(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwRSAKeysSpec,
	char*				pszRSAParamsPath,
	unsigned long				dwECDSAKeysSpec,
	char*				pszECDSAParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	void*				*ppvPrivateKeyContext,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbRSARequest,
	unsigned long*				pdwRSARequest,
	char*				pszRSAReqFileName,
	unsigned char*				*ppbECDSARequest,
	unsigned long*				pdwECDSARequest,
	char*				pszECDSAReqFileName);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxGenerateNamedPrivateKey2Ex(
	void*				pvContext,
	PEU_KEY_MEDIA		pKeyMedia,
	char*				pszNamedPrivateKeyLabel,
	char*				pszNamedPrivateKeyPassword,
	int				bSetKeyMediaPassword,
	unsigned long				dwUAKeysType,
	unsigned long				dwUADSKeysSpec,
	unsigned long				dwUAKEPKeysSpec,
	char*				pszUAParamsPath,
	unsigned long				dwInternationalKeysType,
	unsigned long				dwRSAKeysSpec,
	char*				pszRSAParamsPath,
	unsigned long				dwECDSAKeysSpec,
	char*				pszECDSAParamsPath,
	PEU_USER_INFO		pUserInfo,
	char*				pszExtKeyUsages,
	void*				*ppvPrivateKeyContext,
	unsigned char*				*ppbUARequest,
	unsigned long*				pdwUARequest,
	char*				pszUAReqFileName,
	unsigned char*				*ppbUAKEPRequest,
	unsigned long*				pdwUAKEPRequest,
	char*				pszUAKEPReqFileName,
	unsigned char*				*ppbRSARequest,
	unsigned long*				pdwRSARequest,
	char*				pszRSAReqFileName,
	unsigned char*				*ppbECDSARequest,
	unsigned long*				pdwECDSARequest,
	char*				pszECDSAReqFileName);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_DESTROY_NAMED_PRIVATE_KEY_EX)(
	void*				pvPrivateKeyContext);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxDestroyNamedPrivateKeyEx(
	void*				pvPrivateKeyContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ENVELOP_DATA_RSA)(
	void*			pvPrivateKeyContext,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	unsigned long			dwContentEncAlgoType,
	int			bSignData,
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxEnvelopDataRSA(
	void*			pvPrivateKeyContext,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	unsigned long			dwContentEncAlgoType,
	int			bSignData,
	int			bAppendCert,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CLIENTS_CTX_OPEN)(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	void*			*ppvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUClientsCtxOpen(
	const char*			pszTypeDescription,
	const char*			pszDeviceDescription,
	const char*			pszPassword,
	void*			*ppvDeviceContext);
#endif //PC_STATIC_LIBS

typedef void (*PEU_CLIENTS_CTX_CLOSE)(
	void*			pvDeviceContext);
#ifdef PC_STATIC_LIBS
extern "C"
void EUClientsCtxClose(
	void*			pvDeviceContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CLIENTS_CTX_ENUM_CLIENTS)(
	void*			pvClientsContext,
	unsigned long			dwIndex,
	char*			pszClientName,
	char*			pszClientLogin,
	unsigned long*			pdwClientType,
	char*			pszClientPassword,
	char*			pszClientAddress);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUClientsCtxEnumClients(
	void*			pvClientsContext,
	unsigned long			dwIndex,
	char*			pszClientName,
	char*			pszClientLogin,
	unsigned long*			pdwClientType,
	char*			pszClientPassword,
	char*			pszClientAddress);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CLIENTS_CTX_ADD_CLIENT)(
	void*			pvClientsContext,
	char*			pszClientName,
	char*			pszClientLogin,
	unsigned long			dwClientType,
	char*			pszClientPassword,
	char*			pszClientAddress);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUClientsCtxAddClient(
	void*			pvClientsContext,
	char*			pszClientName,
	char*			pszClientLogin,
	unsigned long			dwClientType,
	char*			pszClientPassword,
	char*			pszClientAddress);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CLIENTS_CTX_CHANGE_CLIENT)(
	void*			pvClientsContext,
	char*			pszClientName,
	char*			pszNewClientName,
	char*			pszNewClientLogin,
	unsigned long			dwNewClientType,
	char*			pszNewClientPassword,
	char*			pszNewClientAddress);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUClientsCtxChangeClient(
	void*			pvClientsContext,
	char*			pszClientName,
	char*			pszNewClientName,
	char*			pszNewClientLogin,
	unsigned long			dwNewClientType,
	char*			pszNewClientPassword,
	char*			pszNewClientAddress);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CLIENTS_CTX_REMOVE_CLIENT)(
	void*			pvClientsContext,
	char*			pszClientName);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUClientsCtxRemoveClient(
	void*			pvClientsContext,
	char*			pszClientName);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_CERT_SUBJECT_PUBLIC_KEY_INFO)(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			*ppbSubjPubKeyInfo,
	unsigned long*			pdwSubjPubKeyInfoLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetCertSubjectPublicKeyInfo(
	unsigned char*			pbCertificate,
	unsigned long			dwCertificateLength,
	unsigned char*			*ppbSubjPubKeyInfo,
	unsigned long*			pdwSubjPubKeyInfoLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_CERT_REQUEST_SUBJECT_PUBLIC_KEY_INFO)(
	unsigned char*			pbRequest,
	unsigned long			dwRequestLength,
	unsigned char*			*ppbSubjPubKeyInfo,
	unsigned long*			pdwSubjPubKeyInfoLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetCertRequestSubjectPublicKeyInfo(
	unsigned char*			pbRequest,
	unsigned long			dwRequestLength,
	unsigned char*			*ppbSubjPubKeyInfo,
	unsigned long*			pdwSubjPubKeyInfoLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_GET_SUBJECT_PUBLIC_KEY_INFO_ID)(
	unsigned char*			pbSubjPubKeyInfo,
	unsigned long			dwSubjPubKeyInfoLength,
	int			bPreferDSTUHash,
	char*			*ppszKeyID);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUGetSubjectPublicKeyInfoID(
	unsigned char*			pbSubjPubKeyInfo,
	unsigned long			dwSubjPubKeyInfoLength,
	int			bPreferDSTUHash,
	char*			*ppszKeyID);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ASIC_APPEND_SIGN)(
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUASiCAppendSign(
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_CTX_ASIC_APPEND_SIGN)(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCtxASiCAppendSign(
	void*				pvPrivateKeyContext,
	unsigned long				dwSignAlgo,
	unsigned long				dwSignLevel,
	char*				pszReferences,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_MAKE_NEW_OWN_CERTIFICATE_WITH_CR)(
	void*				pvPrivateKeyContext,
	unsigned char*				pbUARequest,
	unsigned long				dwUARequest,
	unsigned char*				pbUAKEPRequest,
	unsigned long				dwUAKEPRequest,
	unsigned char*				pbRSARequest,
	unsigned long				dwRSARequest,
	unsigned char*				pbECDSARequest,
	unsigned long				dwECDSARequest);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxMakeNewOwnCertificateWithCR(
	void*				pvPrivateKeyContext,
	unsigned char*				pbUARequest,
	unsigned long				dwUARequest,
	unsigned char*				pbUAKEPRequest,
	unsigned long				dwUAKEPRequest,
	unsigned char*				pbRSARequest,
	unsigned long				dwRSARequest,
	unsigned char*				pbECDSARequest,
	unsigned long				dwECDSARequest);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_GET_PRIVATE_KEY_INFO)(
	void*				pvPrivateKeyContext,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfoLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxGetPrivateKeyInfo(
	void*				pvPrivateKeyContext,
	unsigned char*				*ppbPrivKeyInfo,
	unsigned long*				pdwPrivKeyInfoLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CLIENT_RAW_MULTI_SESSION_CREATE)(
	unsigned long			dwExpireTime,
	unsigned char*			pbServerData,
	unsigned long			dwServerDataLength,
	void*			*ppvClientSession);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUClientRawMultiSessionCreate(
	unsigned long			dwExpireTime,
	unsigned char*			pbServerData,
	unsigned long			dwServerDataLength,
	void*			*ppvClientSession);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_SERVER_RAW_MULTI_SESSION_CREATE)(
	unsigned long			dwExpireTime,
	unsigned long			dwClientsCerts,
	unsigned char*			*ppbClientsCerts,
	unsigned long*			pdwClientsCertsLength,
	unsigned char*			*ppbClientsData,
	unsigned long*			pdwClientsDataLength,
	void*			*ppvServerSession);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUServerRawMultiSessionCreate(
	unsigned long			dwExpireTime,
	unsigned long			dwClientsCerts,
	unsigned char*			*ppbClientsCerts,
	unsigned long*			pdwClientsCertsLength,
	unsigned char*			*ppbClientsData,
	unsigned long*			pdwClientsDataLength,
	void*			*ppvServerSession);
#endif // PC_STATIC_LIBS

//------------------------------------------------------------------------------

typedef unsigned long (*PEU_RAW_MULTI_SESSION_ADD_CLIENTS)(
	void*			pvSession,
	unsigned long			dwClientsCerts,
	unsigned char*			*ppbClientsCerts,
	unsigned long*			pdwClientsCertsLength,
	unsigned char*			*ppbClientsData,
	unsigned long*			pdwClientsDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EURawMultiSessionAddClients(
	void*			pvSession,
	unsigned long			dwClientsCerts,
	unsigned char*			*ppbClientsCerts,
	unsigned long*			pdwClientsCertsLength,
	unsigned char*			*ppbClientsData,
	unsigned long*			pdwClientsDataLength);
#endif // PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_TSL_SETTINGS)(
	int*			pbUseTSL,
	int*			pbAutoDownloadTSL,
	char*			pszTSLAddress);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetTSLSettings(
	int*			pbUseTSL,
	int*			pbAutoDownloadTSL,
	char*			pszTSLAddress);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_TSL_SETTINGS)(
	int			bUseTSL,
	int			bAutoDownloadTSL,
	char*			pszTSLAddress);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetTSLSettings(
	int			bUseTSL,
	int			bAutoDownloadTSL,
	char*			pszTSLAddress);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_SAVE_TSL)(
	unsigned char*				pbTSL,
	unsigned long				dwTSLLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSaveTSL(
	unsigned char*				pbTSL,
	unsigned long				dwTSLLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_GET_LOG_SETTINGS)(
	int*			pbSystem,
	int*			pbUseReportAgent,
	char*			pszReportAgentAddress,
	char*			pszReportAgentPort,
	int*			pbOnlyErrors);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUGetLogSettings(
	int*			pbSystem,
	int*			pbUseReportAgent,
	char*			pszReportAgentAddress,
	char*			pszReportAgentPort,
	int*			pbOnlyErrors);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_SET_LOG_SETTINGS)(
	int			bSystem,
	int			bUseReportAgent,
	char*			pszReportAgentAddress,
	char*			pszReportAgentPort,
	int			bOnlyErrors);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUSetLogSettings(
	int			bSystem,
	int			bUseReportAgent,
	char*			pszReportAgentAddress,
	char*			pszReportAgentPort,
	int			bOnlyErrors);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SERVER_SESSION_CREATE_STEP1_EX)(
	unsigned long			dwExpireTime,
	unsigned long			dwEncAlgo,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUServerSessionCreateStep1Ex(
	unsigned long			dwExpireTime,
	unsigned long			dwEncAlgo,
	unsigned char*			pbClientData,
	unsigned long			dwClientDataLength,
	void*			*ppvServerSession,
	unsigned char*			*ppbServerData,
	unsigned long*			pdwServerDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_SETTINGS_EX)(
	unsigned long			dwContentEncAlgoType,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertsOffline,
	int			bCheckRecipientCertsNoCRL,
	int			bNoTSP,
	int			bAppendCert,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUEnvelopDataToRecipientsWithSettingsEx(
	unsigned long			dwContentEncAlgoType,
	unsigned long			dwRecipientCerts,
	unsigned char*			*ppbRecipientCerts,
	unsigned long*			pdwRecipientCertsLength,
	int			bSignData,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckRecipientCertsOffline,
	int			bCheckRecipientCertsNoCRL,
	int			bNoTSP,
	int			bAppendCert,
	char*			*ppszEnvelopedData,
	unsigned char*			*ppbEnvelopedData,
	unsigned long*			pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ASIC_CREATE_EMPTY_SIGN)(
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUASiCCreateEmptySign(
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	char*				pszReferences,
	unsigned char*				*ppbReferences,
	unsigned long*				pdwReferencesLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ASIC_CREATE_SIGNER_BEGIN)(
	unsigned long				dwSignAlgo,
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	char*				pszReferences,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	char*				*ppszSignatureReference,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUASiCCreateSignerBegin(
	unsigned long				dwSignAlgo,
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	char*				pszReferences,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	char*				*ppszSignatureReference,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_ASIC_CREATE_SIGNER_END)(
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	unsigned long				dwSignLevel,
	char*				pszSignatureReference,
	unsigned char*				pbSignature,
	unsigned long				dwSignatureLength,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUASiCCreateSignerEnd(
	unsigned long				dwASiCType,
	unsigned long				dwSignType,
	unsigned long				dwSignLevel,
	char*				pszSignatureReference,
	unsigned char*				pbSignature,
	unsigned long				dwSignatureLength,
	unsigned char*				pbPreviousASiCData,
	unsigned long				dwPreviousASiCDataLength,
	unsigned char*				*ppbASiCData,
	unsigned long*				pdwASiCDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_INTERNAL_AUTHENTICATE_IDCARD_WITH_IGNORING_KEY)(
	void*				pvDeviceContext,
	unsigned long				dwCVCertificates,
	unsigned char*				*ppbCVCertificates,
	unsigned long*				pdwCVCertificatesLength,
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	const char*				pszPassword,
	unsigned char*				pbIgnoringPrivateKey,
	unsigned long				dwIgnoringPrivateKeyLength,
	const char*				pszIgnoringPrivateKeyPassword);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUDevCtxInternalAuthenticateIDCardWithIgnoringKey(
	void*				pvDeviceContext,
	unsigned long				dwCVCertificates,
	unsigned char*				*ppbCVCertificates,
	unsigned long*				pdwCVCertificatesLength,
	unsigned char*				pbPrivateKey,
	unsigned long				dwPrivateKeyLength,
	const char*				pszPassword,
	unsigned char*				pbIgnoringPrivateKey,
	unsigned long				dwIgnoringPrivateKeyLength,
	const char*				pszIgnoringPrivateKeyPassword);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_ENVELOP_DATA_WITH_SETTINGS)(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bCheckRecipientCertsOffline,
	int				bCheckRecipientCertsNoCRL,
	int				bNoRecipientCertsCertCheck,
	int				bSignData,
	int				bNoTSP,
	int				bAppendCert,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxEnvelopDataWithSettings(
	void*				pvPrivateKeyContext,
	unsigned long				dwRecipientCerts,
	unsigned char*				*ppbRecipientCerts,
	unsigned long*				pdwRecipientCertsLength,
	unsigned long				dwRecipientAppendType,
	int				bCheckRecipientCertsOffline,
	int				bCheckRecipientCertsNoCRL,
	int				bNoRecipientCertsCertCheck,
	int				bSignData,
	int				bNoTSP,
	int				bAppendCert,
	unsigned char*				pbData,
	unsigned long				dwDataLength,
	unsigned char*				*ppbEnvelopedData,
	unsigned long*				pdwEnvelopedDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CTX_GET_SSERVER_CLIENT_REGISTRATION_TOKEN)(
	void*				pvPrivateKeyContext,
	unsigned long				dwRegTokenRequestNameType,
	char*				pszRegTokenName,
	char*				*ppszToken);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUCtxGetSServerClientRegistrationToken(
	void*				pvPrivateKeyContext,
	unsigned long				dwRegTokenRequestNameType,
	char*				pszRegTokenName,
	char*				*ppszToken);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_NBU_SIGN_DATA)(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckKeyLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUNBUSignData(
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	int			bCheckKeyLength,
	char*			*ppszSign,
	unsigned char*			*ppbSign,
	unsigned long*			pdwSignLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_NBU_VERIFY_DATA)(
	char*			pszNBUCode,
	int			bCMPSupportsJSONRequests,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUNBUVerifyData(
	char*			pszNBUCode,
	int			bCMPSupportsJSONRequests,
	unsigned char*			pbData,
	unsigned long			dwDataLength,
	char*			pszSign,
	unsigned char*			pbSign,
	unsigned long			dwSignLength,
	PEU_SIGN_INFO	pSignInfo);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_PDF_CREATE_SIGNER_BEGIN)(
	unsigned long				dwSignAlgo,
	unsigned char*				pbPDFData,
	unsigned long				dwPDFDataLength,
	char*				*ppszSignatureReference,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUPDFCreateSignerBegin(
	unsigned long				dwSignAlgo,
	unsigned char*				pbPDFData,
	unsigned long				dwPDFDataLength,
	char*				*ppszSignatureReference,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#endif //PC_STATIC_LIBS

//-----------------------------------------------------------------------------

typedef unsigned long (*PEU_PDF_CREATE_SIGNER_END)(
	unsigned char*				pbPreviousPDFData,
	unsigned long				dwPreviousPDFDataLength,
	unsigned long				dwSignType,
	char*				pszSignatureReference,
	unsigned char*				pbSignature,
	unsigned long				dwSignatureLength,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUPDFCreateSignerEnd(
	unsigned char*				pbPreviousPDFData,
	unsigned long				dwPreviousPDFDataLength,
	unsigned long				dwSignType,
	char*				pszSignatureReference,
	unsigned char*				pbSignature,
	unsigned long				dwSignatureLength,
	unsigned char*				*ppbSignedPDFData,
	unsigned long*				pdwSignedPDFDataLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_CREATE_SIGNER_BEGIN_EX)(
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bNoSigningTime,
	int				bNoContentTimeStamp,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUCreateSignerBeginEx(
	unsigned char*				pbSignerCert,
	unsigned long				dwSignerCertLength,
	unsigned char*				pbHash,
	unsigned long				dwHashLength,
	int				bNoSigningTime,
	int				bNoContentTimeStamp,
	unsigned char*				*ppbSigner,
	unsigned long*				pdwSignerLength,
	unsigned char*				*ppbAttrsHash,
	unsigned long*				pdwAttrsHashLength);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_ALGO_CTX_CREATE)(
	unsigned long				dwAlgo,
	void*				*ppvAlgoContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxCreate(
	unsigned long				dwAlgo,
	void*				*ppvAlgoContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ALGO_CTX_GENERATE_KEY)(
	void*				pvAlgoContext);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxGenerateKey(
	void*				pvAlgoContext);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ALGO_CTX_SET_KEY)(
	void*				pvAlgoContext,
	unsigned char*				pbKey,
	unsigned long				dwKey,
	unsigned char*				pbIV,
	unsigned long				dwIV);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxSetKey(
	void*				pvAlgoContext,
	unsigned char*				pbKey,
	unsigned long				dwKey,
	unsigned char*				pbIV,
	unsigned long				dwIV);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ALGO_CTX_GET_KEY_SIZE)(
	void*				pvAlgoContext,
	unsigned long*				pdwKey,
	unsigned long*				pdwIV);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxGetKeySize(
	void*				pvAlgoContext,
	unsigned long*				pdwKey,
	unsigned long*				pdwIV);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ALGO_CTX_GET_KEY)(
	void*				pvAlgoContext,
	unsigned char*				pbKey,
	unsigned long				dwKey,
	unsigned char*				pbIV,
	unsigned long				dwIV);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxGetKey(
	void*				pvAlgoContext,
	unsigned char*				pbKey,
	unsigned long				dwKey,
	unsigned char*				pbIV,
	unsigned long				dwIV);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ALGO_CTX_ENCRYPT)(
	void*				pvAlgoContext,
	unsigned char*				pbData,
	unsigned long				dwData);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxEncrypt(
	void*				pvAlgoContext,
	unsigned char*				pbData,
	unsigned long				dwData);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ALGO_CTX_DECRYPT)(
	void*				pvAlgoContext,
	unsigned char*				pbData,
	unsigned long				dwData);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxDecrypt(
	void*				pvAlgoContext,
	unsigned char*				pbData,
	unsigned long				dwData);
#endif //PC_STATIC_LIBS

typedef unsigned long (*PEU_ALGO_CTX_GET_DATA_MAC)(
	void*				pvAlgoContext,
	unsigned char*				pbData,
	unsigned long				dwData,
	unsigned char*				pbMAC,
	unsigned long				dwMAC);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUAlgoCtxGetDataMAC(
	void*				pvAlgoContext,
	unsigned char*				pbData,
	unsigned long				dwData,
	unsigned char*				pbMAC,
	unsigned long				dwMAC);
#endif //PC_STATIC_LIBS

typedef void (*PEU_ALGO_CTX_FREE)(
	void*				pvAlgoContext);
#ifdef PC_STATIC_LIBS
extern "C"
void EUAlgoCtxFree(
	void*				pvAlgoContext);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_SSERVER_CLIENT_RESET_OPERATION)(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUSServerClientResetOperation(
	char*				pszServerAddress,
	char*				pszServerPort,
	char*				pszClientID,
	char*				pszOperationID);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_DEV_CTX_GENERATE_IDCARD_IS_PRIVATE_KEY)(
	void*			pvDeviceContext,
	unsigned long			dwKeysType,
	char*			pszPassword,
	char*			pszCountry,
	char*			pszName,
	unsigned long			dwNumber,
	unsigned char*			*ppbPrivateKey,
	unsigned long*			pdwPrivateKey,
	unsigned char*			*ppbCVRequest,
	unsigned long*			pdwCVRequest);
#ifdef PC_STATIC_LIBS
extern "C" unsigned long EUDevCtxGenerateIDCardISPrivateKey(
	void*			pvDeviceContext,
	unsigned long			dwKeysType,
	char*			pszPassword,
	char*			pszCountry,
	char*			pszName,
	unsigned long			dwNumber,
	unsigned char*			*ppbPrivateKey,
	unsigned long*			pdwPrivateKey,
	unsigned char*			*ppbCVRequest,
	unsigned long*			pdwCVRequest);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef unsigned long (*PEU_INITIALIZE_CERTIFICATE_STATUS_CACHE)(
	unsigned long			dwMinSize,
	unsigned long			dwCachePeriod);
#ifdef PC_STATIC_LIBS
extern "C"
unsigned long EUInitializeCertificateStatusCache(
	unsigned long			dwMinSize,
	unsigned long			dwCachePeriod);
#endif //PC_STATIC_LIBS

//==============================================================================

typedef struct
{
	PEU_INITIALIZE				Initialize;
	PEU_IS_INITIALIZED			IsInitialized;
	PEU_FINALIZE				Finalize;

	PEU_SET_SETTINGS			SetSettings;

	PEU_SHOW_CERTIFICATES		ShowCertificates;
	PEU_SHOW_CRLS				ShowCRLs;

	PEU_GET_PRIVATE_KEY_MEDIA	GetPrivateKeyMedia;
	PEU_READ_PRIVATE_KEY		ReadPrivateKey;
	PEU_IS_PRIVATE_KEY_READED	IsPrivateKeyReaded;
	PEU_RESET_PRIVATE_KEY		ResetPrivateKey;
	PEU_FREE_CERT_OWNER_INFO	FreeCertOwnerInfo;

	PEU_SHOW_OWN_CERTIFICATE	ShowOwnCertificate;
	PEU_SHOW_SIGN_INFO			ShowSignInfo;
	PEU_FREE_SIGN_INFO			FreeSignInfo;

	PEU_FREE_MEMORY				FreeMemory;

	PEU_GET_ERROR_DESC			GetErrorDesc;

	PEU_SIGN_DATA				SignData;
	PEU_VERIFY_DATA				VerifyData;

	PEU_SIGN_DATA_CONTINUE		SignDataContinue;
	PEU_SIGN_DATA_END			SignDataEnd;
	PEU_VERIFY_DATA_BEGIN		VerifyDataBegin;
	PEU_VERIFY_DATA_CONTINUE	VerifyDataContinue;
	PEU_VERIFY_DATA_END			VerifyDataEnd;
	PEU_RESET_OPERATION			ResetOperation;

	PEU_SIGN_FILE				SignFile;
	PEU_VERIFY_FILE				VerifyFile;

	PEU_SIGN_DATA_INTERNAL		SignDataInternal;
	PEU_VERIFY_DATA_INTERNAL	VerifyDataInternal;

	PEU_SELECT_CERTIFICATE_INFO	SelectCertInfo;

	PEU_SET_UI_MODE				SetUIMode;

	PEU_HASH_DATA				HashData;
	PEU_HASH_DATA_CONTINUE		HashDataContinue;
	PEU_HASH_DATA_END			HashDataEnd;
	PEU_HASH_FILE				HashFile;
	PEU_SIGN_HASH				SignHash;
	PEU_VERIFY_HASH				VerifyHash;

	PEU_ENUM_KEY_MEDIA_TYPES	EnumKeyMediaTypes;
	PEU_ENUM_KEY_MEDIA_DEVICES	EnumKeyMediaDevices;

	PEU_GET_FILE_STORE_SETTINGS	GetFileStoreSettings;
	PEU_SET_FILE_STORE_SETTINGS	SetFileStoreSettings;
	PEU_GET_PROXY_SETTINGS		GetProxySettings;
	PEU_SET_PROXY_SETTINGS		SetProxySettings;
	PEU_GET_OCSP_SETTINGS		GetOCSPSettings;
	PEU_SET_OCSP_SETTINGS		SetOCSPSettings;
	PEU_GET_TSP_SETTINGS		GetTSPSettings;
	PEU_SET_TSP_SETTINGS		SetTSPSettings;
	PEU_GET_LDAP_SETTINGS		GetLDAPSettings;
	PEU_SET_LDAP_SETTINGS		SetLDAPSettings;

	PEU_GET_CERTIFICATES_COUNT	GetCertificatesCount;
	PEU_ENUM_CERTIFICATES		EnumCertificates;
	PEU_GET_CRLS_COUNT			GetCRLsCount;
	PEU_ENUM_CRLS				EnumCRLs;
	PEU_FREE_CRL_INFO			FreeCRLInfo;

	PEU_GET_CERTIFICATE_INFO	GetCertificateInfo;
	PEU_FREE_CERTIFICATE_INFO	FreeCertificateInfo;
	PEU_GET_CRL_DETAILED_INFO	GetCRLDetailedInfo;
	PEU_FREE_CRL_DETAILED_INFO	FreeCRLDetailedInfo;

	PEU_GET_CMP_SETTINGS		GetCMPSettings;
	PEU_SET_CMP_SETTINGS		SetCMPSettings;
	PEU_DOES_NEED_SET_SETTINGS	DoesNeedSetSettings;

	PEU_GET_PRIVATE_KEY_MEDIA_SETTINGS
								GetPrivateKeyMediaSettings;
	PEU_SET_PRIVATE_KEY_MEDIA_SETTINGS
								SetPrivateKeyMediaSettings;

	PEU_SELECT_CMP_SERVER		SelectCMPServer;

	PEU_RAW_SIGN_DATA			RawSignData;
	PEU_RAW_VERIFY_DATA			RawVerifyData;
	PEU_RAW_SIGN_HASH			RawSignHash;
	PEU_RAW_VERIFY_HASH			RawVerifyHash;
	PEU_RAW_SIGN_FILE			RawSignFile;
	PEU_RAW_VERIFY_FILE			RawVerifyFile;

	PEU_BASE64_ENCODE			BASE64Encode;
	PEU_BASE64_DECODE			BASE64Decode;

	PEU_ENVELOP_DATA			EnvelopData;
	PEU_DEVELOP_DATA			DevelopData;
	PEU_SHOW_SENDER_INFO		ShowSenderInfo;
	PEU_FREE_SENDER_INFO		FreeSenderInfo;

	PEU_PARSE_CERTIFICATE		ParseCertificate;

	PEU_READ_PRIVATE_KEY_BINARY	ReadPrivateKeyBinary;
	PEU_READ_PRIVATE_KEY_FILE	ReadPrivateKeyFile;

	PEU_SESSION_DESTROY			SessionDestroy;
	PEU_CLIENT_SESSION_CREATE_STEP1
								ClientSessionCreateStep1;
	PEU_SERVER_SESSION_CREATE_STEP1
								ServerSessionCreateStep1;
	PEU_CLIENT_SESSION_CREATE_STEP2
								ClientSessionCreateStep2;
	PEU_SERVER_SESSION_CREATE_STEP2
								ServerSessionCreateStep2;
	PEU_SESSION_IS_INITIALIZED	SessionIsInitialized;
	PEU_SESSION_SAVE			SessionSave;
	PEU_SESSION_LOAD			SessionLoad;
	PEU_SESSION_CHECK_CERTIFICATES
								SessionCheckCertificates;
	PEU_SESSION_ENCRYPT			SessionEncrypt;
	PEU_SESSION_ENCRYPT_CONTINUE
								SessionEncryptContinue;
	PEU_SESSION_DECRYPT			SessionDecrypt;
	PEU_SESSION_DECRYPT_CONTINUE
								SessionDecryptContinue;

	PEU_IS_SIGNED_DATA			IsSignedData;
	PEU_IS_ENVELOPED_DATA		IsEnvelopedData;

	PEU_SESSION_GET_PEER_CERTIFICATE_INFO
								SessionGetPeerCertificateInfo;

	PEU_SAVE_CERTIFICATE		SaveCertificate;
	PEU_REFRESH_FILE_STORE		RefreshFileStore;

	PEU_GET_MODE_SETTINGS		GetModeSettings;
	PEU_SET_MODE_SETTINGS		SetModeSettings;

	PEU_CHECK_CERTIFICATE		CheckCertificate;

	PEU_ENVELOP_FILE			EnvelopFile;
	PEU_DEVELOP_FILE			DevelopFile;
	PEU_IS_SIGNED_FILE			IsSignedFile;
	PEU_IS_ENVELOPED_FILE		IsEnvelopedFile;

	PEU_GET_CERTIFICATE			GetCertificate;
	PEU_GET_OWN_CERTIFICATE		GetOwnCertificate;

	PEU_ENUM_OWN_CERTIFICATES	EnumOwnCertificates;
	PEU_GET_CERTIFICATE_INFO_EX GetCertificateInfoEx;
	PEU_FREE_CERTIFICATE_INFO_EX
								FreeCertificateInfoEx;

	PEU_GET_RECEIVERS_CERTIFICATES
								GetReceiversCertificates;
	PEU_FREE_RECEIVERS_CERTIFICATES
								FreeReceiversCertificates;

	PEU_GENERATE_PRIVATE_KEY	GeneratePrivateKey;
	PEU_CHANGE_PRIVATE_KEY_PASSWORD
								ChangePrivateKeyPassword;
	PEU_BACKUP_PRIVATE_KEY		BackupPrivateKey;
	PEU_DESTROY_PRIVATE_KEY		DestroyPrivateKey;
	PEU_IS_HARDWARE_KEY_MEDIA	IsHardwareKeyMedia;
	PEU_IS_PRIVATE_KEY_EXISTS	IsPrivateKeyExists;

	PEU_GET_CR_INFO				GetCRInfo;
	PEU_FREE_CR_INFO			FreeCRInfo;

	PEU_SAVE_CERTIFICATES		SaveCertificates;
	PEU_SAVE_CRL				SaveCRL;

	PEU_GET_CERTIFICATE_BY_EMAIL
								GetCertificateByEMail;
	PEU_GET_CERTIFICATE_BY_NBU_CODE
								GetCertificateByNBUCode;

	PEU_APPEND_SIGN				AppendSign;
	PEU_APPEND_SIGN_INTERNAL	AppendSignInternal;
	PEU_VERIFY_DATA_SPECIFIC	VerifyDataSpecific;
	PEU_VERIFY_DATA_INTERNAL_SPECIFIC
								VerifyDataInternalSpecific;
	PEU_APPEND_SIGN_BEGIN		AppendSignBegin;
	PEU_VERIFY_DATA_SPECIFIC_BEGIN
								VerifyDataSpecificBegin;
	PEU_APPEND_SIGN_FILE		AppendSignFile;
	PEU_VERIFY_FILE_SPECIFIC	VerifyFileSpecific;
	PEU_APPEND_SIGN_HASH		AppendSignHash;
	PEU_VERIFY_HASH_SPECIFIC	VerifyHashSpecific;
	PEU_GET_SIGNS_COUNT			GetSignsCount;
	PEU_GET_SIGNER_INFO			GetSignerInfo;
	PEU_GET_FILE_SIGNS_COUNT	GetFileSignsCount;
	PEU_GET_FILE_SIGNER_INFO	GetFileSignerInfo;

	PEU_IS_ALREADY_SIGNED		IsAlreadySigned;
	PEU_IS_FILE_ALREADY_SIGNED	IsFileAlreadySigned;

	PEU_HASH_DATA_WITH_PARAMS	HashDataWithParams;
	PEU_HASH_DATA_BEGIN_WITH_PARAMS
								HashDataBeginWithParams;
	PEU_HASH_FILE_WITH_PARAMS	HashFileWithParams;

	PEU_ENVELOP_DATA_EX			EnvelopDataEx;

	PEU_SET_SETTINGS_FILE_PATH	SetSettingsFilePath;

	PEU_SET_KEY_MEDIA_PASSWORD	SetKeyMediaPassword;
	PEU_GENERATE_PRIVATE_KEY_EX	GeneratePrivateKeyEx;

	PEU_GET_ERROR_LANG_DESC		GetErrorLangDesc;

	PEU_ENVELOP_FILE_EX			EnvelopFileEx;

	PEU_IS_CERTIFICATES			IsCertificates;
	PEU_IS_CERTIFICATES_FILE	IsCertificatesFile;

	PEU_ENUM_CERTIFICATES_BY_O_CODE
								EnumCertificatesByOCode;
	PEU_GET_CERTIFICATES_BY_O_CODE
								GetCertificatesByOCode;

	PEU_SET_PRIVATE_KEY_MEDIA_SETTINGS_PROTECTED
								SetPrivateKeyMediaSettingsProtected;

	PEU_ENVELOP_DATA_TO_RECIPIENTS
								EnvelopDataToRecipients;
	PEU_ENVELOP_FILE_TO_RECIPIENTS
								EnvelopFileToRecipients;

	PEU_ENVELOP_DATA_EX_WITH_DYNAMIC_KEY
								EnvelopDataExWithDynamicKey;
	PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_DYNAMIC_KEY
								EnvelopDataToRecipientsWithDynamicKey;
	PEU_ENVELOP_FILE_EX_WITH_DYNAMIC_KEY
								EnvelopFileExWithDynamicKey;
	PEU_ENVELOP_FILE_TO_RECIPIENTS_WITH_DYNAMIC_KEY
								EnvelopFileToRecipientsWithDynamicKey;

	PEU_SAVE_PRIVATE_KEY		SavePrivateKey;
	PEU_LOAD_PRIVATE_KEY		LoadPrivateKey;
	PEU_CHANGE_SOFTWARE_PRIVATE_KEY_PASSWORD 
								ChangeSoftwarePrivateKeyPassword;

	PEU_HASH_DATA_BEGIN_WITH_PARAMS_CTX
								HashDataBeginWithParamsCtx;
	PEU_HASH_DATA_CONTINUE_CTX	HashDataContinueCtx;
	PEU_HASH_DATA_END_CTX		HashDataEndCtx;

	PEU_GET_CERTIFICATE_BY_KEY_INFO
								GetCertificateByKeyInfo;

	PEU_SAVE_PRIVATE_KEY_EX		SavePrivateKeyEx;
	PEU_LOAD_PRIVATE_KEY_EX		LoadPrivateKeyEx;

	PEU_CREATE_EMPTY_SIGN		CreateEmptySign;
	PEU_CREATE_SIGNER			CreateSigner;
	PEU_APPEND_SIGNER			AppendSigner;

	PEU_SET_RUNTIME_PARAMETER	SetRuntimeParameter;

	PEU_ENVELOP_DATA_TO_RECIPIENTS_EX
								EnvelopDataToRecipientsEx;
	PEU_ENVELOP_FILE_TO_RECIPIENTS_EX
								EnvelopFileToRecipientsEx;
	PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_O_CODE
								EnvelopDataToRecipientsWithOCode;

	PEU_SIGN_DATA_CONTINUE_CTX	SignDataContinueCtx;
	PEU_SIGN_DATA_END_CTX		SignDataEndCtx;
	PEU_VERIFY_DATA_BEGIN_CTX	VerifyDataBeginCtx;
	PEU_VERIFY_DATA_CONTINUE_CTX
								VerifyDataContinueCtx;
	PEU_VERIFY_DATA_END_CTX		VerifyDataEndCtx;
	PEU_RESET_OPERATION_CTX		ResetOperationCtx;

	PEU_SIGN_DATA_RSA			SignDataRSA;
	PEU_SIGN_DATA_RSA_CONTINUE	SignDataRSAContinue;
	PEU_SIGN_DATA_RSA_END		SignDataRSAEnd;
	PEU_SIGN_FILE_RSA			SignFileRSA;
	PEU_SIGN_DATA_RSA_CONTINUE_CTX 
								SignDataRSAContinueCtx;
	PEU_SIGN_DATA_RSA_END_CTX	SignDataRSAEndCtx;

	PEU_DOWNLOAD_FILE_VIA_HTTP	DownloadFileViaHTTP;

	PEU_PARSE_CRL				ParseCRL;

	PEU_IS_OLD_FORMAT_SIGN		IsOldFormatSign;
	PEU_IS_OLD_FORMAT_SIGN_FILE	IsOldFormatSignFile;

	PEU_GET_PRIVATE_KEY_MEDIA_EX
								GetPrivateKeyMediaEx;

	PEU_GET_KEY_INFO			GetKeyInfo;
	PEU_GET_KEY_INFO_BINARY		GetKeyInfoBinary;
	PEU_GET_KEY_INFO_FILE		GetKeyInfoFile;
	PEU_GET_CERTIFICATES_BY_KEY_INFO
								GetCertificatesByKeyInfo;

	PEU_ENVELOP_APPEND_DATA		EnvelopAppendData;
	PEU_ENVELOP_APPEND_FILE		EnvelopAppendFile;
	PEU_ENVELOP_APPEND_DATA_EX	EnvelopAppendDataEx;
	PEU_ENVELOP_APPEND_FILE_EX	EnvelopAppendFileEx;

	PEU_GET_STORAGE_PARAMETER	GetStorageParameter;
	PEU_SET_STORAGE_PARAMETER	SetStorageParameter;

	PEU_DEVELOP_DATA_EX			DevelopDataEx;
	PEU_DEVELOP_FILE_EX			DevelopFileEx;

	PEU_GET_OCSP_ACCESS_INFO_MODE_SETTINGS
								GetOCSPAccessInfoModeSettings;
	PEU_SET_OCSP_ACCESS_INFO_MODE_SETTINGS
								SetOCSPAccessInfoModeSettings;

	PEU_ENUM_OCSP_ACCESS_INFO_SETTINGS
								EnumOCSPAccessInfoSettings;
	PEU_GET_OCSP_ACCESS_INFO_SETTINGS
								GetOCSPAccessInfoSettings;
	PEU_SET_OCSP_ACCESS_INFO_SETTINGS
								SetOCSPAccessInfoSettings;
	PEU_DELETE_OCSP_ACCESS_INFO_SETTINGS
								DeleteOCSPAccessInfoSettings;

	PEU_CHECK_CERTIFICATE_BY_ISSUER_AND_SERIAL
								CheckCertificateByIssuerAndSerial;

	PEU_PARSE_CERTIFICATE_EX	ParseCertificateEx;

	PEU_CHECK_CERTIFICATE_BY_ISSUER_AND_SERIAL_EX
								CheckCertificateByIssuerAndSerialEx;

	PEU_CLIENT_DYNAMIC_KEY_SESSION_CREATE
								ClientDynamicKeySessionCreate;
	PEU_SERVER_DYNAMIC_KEY_SESSION_CREATE
								ServerDynamicKeySessionCreate;

	PEU_GET_SENDER_INFO			GetSenderInfo;
	PEU_GET_FILE_SENDER_INFO	GetFileSenderInfo;

	PEU_SC_CLIENT_IS_RUNNING	SCClientIsRunning;
	PEU_SC_CLIENT_START			SCClientStart;
	PEU_SC_CLIENT_STOP			SCClientStop;
	PEU_SC_CLIENT_ADD_GATE		SCClientAddGate;
	PEU_SC_CLIENT_REMOVE_GATE	SCClientRemoveGate;
	PEU_SC_CLIENT_GET_STATISTIC	SCClientGetStatistic;
	PEU_SC_CLIENT_FREE_STATISTIC
								SCClientFreeStatistic;

	PEU_GET_RECIPIENTS_COUNT	GetRecipientsCount;
	PEU_GET_FILE_RECIPIENTS_COUNT
								GetFileRecipientsCount;
	PEU_GET_RECIPIENT_INFO		GetRecipientInfo;
	PEU_GET_FILE_RECIPIENT_INFO	GetFileRecipientInfo;

	PEU_CTX_CREATE				CtxCreate;
	PEU_CTX_FREE				CtxFree;
	PEU_CTX_SET_PARAMETER		CtxSetParameter;
	PEU_CTX_READ_PRIVATE_KEY	CtxReadPrivateKey;
	PEU_CTX_READ_PRIVATE_KEY_BINARY
								CtxReadPrivateKeyBinary;
	PEU_CTX_READ_PRIVATE_KEY_FILE
								CtxReadPrivateKeyFile;
	PEU_CTX_FREE_PRIVATE_KEY	CtxFreePrivateKey;

	PEU_CTX_DEVELOP_DATA		CtxDevelopData;
	PEU_CTX_DEVELOP_FILE		CtxDevelopFile;

	PEU_CTX_FREE_MEMORY			CtxFreeMemory;
	PEU_CTX_FREE_CERT_OWNER_INFO
								CtxFreeCertOwnerInfo;
	PEU_CTX_FREE_CERTIFICATE_INFO_EX
								CtxFreeCertificateInfoEx;
	PEU_CTX_FREE_SIGN_INFO		CtxFreeSignInfo;
	PEU_CTX_FREE_SENDER_INFO	CtxFreeSenderInfo;

	PEU_CTX_GET_OWN_CERTIFICATE	CtxGetOwnCertificate;
	PEU_CTX_ENUM_OWN_CERTIFICATES 
								CtxEnumOwnCertificates;

	PEU_CTX_HASH_DATA			CtxHashData;
	PEU_CTX_HASH_FILE			CtxHashFile;
	PEU_CTX_HASH_DATA_BEGIN		CtxHashDataBegin;
	PEU_CTX_HASH_DATA_CONTINUE	CtxHashDataContinue;
	PEU_CTX_HASH_DATA_END		CtxHashDataEnd;
	PEU_CTX_FREE_HASH			CtxFreeHash;

	PEU_CTX_SIGN_HASH			CtxSignHash;
	PEU_CTX_SIGN_HASH_VALUE		CtxSignHashValue;
	PEU_CTX_SIGN_DATA			CtxSignData;
	PEU_CTX_SIGN_FILE			CtxSignFile;
	PEU_CTX_IS_ALREADY_SIGNED	CtxIsAlreadySigned;
	PEU_CTX_IS_FILE_ALREADY_SIGNED
								CtxIsFileAlreadySigned;
	PEU_CTX_APPEND_SIGN_HASH	CtxAppendSignHash;
	PEU_CTX_APPEND_SIGN_HASH_VALUE
								CtxAppendSignHashValue;
	PEU_CTX_APPEND_SIGN			CtxAppendSign;
	PEU_CTX_APPEND_SIGN_FILE	CtxAppendSignFile;
	PEU_CTX_CREATE_EMPTY_SIGN	CtxCreateEmptySign;
	PEU_CTX_CREATE_SIGNER		CtxCreateSigner;
	PEU_CTX_APPEND_SIGNER		CtxAppendSigner;
	PEU_CTX_GET_SIGNS_COUNT		CtxGetSignsCount;
	PEU_CTX_GET_FILE_SIGNS_COUNT
								CtxGetFileSignsCount;
	PEU_CTX_GET_SIGNER_INFO		CtxGetSignerInfo;
	PEU_CTX_GET_FILE_SIGNER_INFO
								CtxGetFileSignerInfo;
	PEU_CTX_VERIFY_HASH			CtxVerifyHash;
	PEU_CTX_VERIFY_HASH_VALUE	CtxVerifyHashValue;
	PEU_CTX_VERIFY_DATA			CtxVerifyData;
	PEU_CTX_VERIFY_DATA_INTERNAL
								CtxVerifyDataInternal;
	PEU_CTX_VERIFY_FILE			CtxVerifyFile;

	PEU_CTX_ENVELOP_DATA		CtxEnvelopData;
	PEU_CTX_ENVELOP_FILE		CtxEnvelopFile;
	PEU_CTX_GET_SENDER_INFO		CtxGetSenderInfo;
	PEU_CTX_GET_FILE_SENDER_INFO
								CtxGetFileSenderInfo;
	PEU_CTX_GET_RECIPIENTS_COUNT
								CtxGetRecipientsCount;
	PEU_CTX_GET_FILE_RECIPIENTS_COUNT
								CtxGetFileRecipientsCount;
	PEU_CTX_GET_RECIPIENT_INFO	CtxGetRecipientInfo;
	PEU_CTX_GET_FILE_RECIPIENT_INFO
								CtxGetFileRecipientInfo;
	PEU_CTX_ENVELOP_APPEND_DATA	CtxEnvelopAppendData;
	PEU_CTX_ENVELOP_APPEND_FILE	CtxEnvelopAppendFile;

	PEU_ENUM_JKS_PRIVATE_KEYS	EnumJKSPrivateKeys;
	PEU_ENUM_JKS_PRIVATE_KEYS_FILE
								EnumJKSPrivateKeysFile;
	PEU_FREE_CERTIFICATES_ARRAY	FreeCertificatesArray;
	PEU_GET_JKS_PRIVATE_KEY		GetJKSPrivateKey;
	PEU_GET_JKS_PRIVATE_KEY_FILE
								GetJKSPrivateKeyFile;

	PEU_CTX_GET_DATA_FROM_SIGNED_DATA
								CtxGetDataFromSignedData;
	PEU_CTX_GET_DATA_FROM_SIGNED_FILE
								CtxGetDataFromSignedFile;

	PEU_SET_SETTINGS_REG_PATH	SetSettingsRegPath;

	PEU_CTX_IS_DATA_IN_SIGNED_DATA_AVAILABLE
								CtxIsDataInSignedDataAvailable;
	PEU_CTX_IS_DATA_IN_SIGNED_FILE_AVAILABLE
								CtxIsDataInSignedFileAvailable;

	PEU_GET_CERTIFICATE_FROM_SIGNED_DATA
								GetCertificateFromSignedData;
	PEU_GET_CERTIFICATE_FROM_SIGNED_FILE
								GetCertificateFromSignedFile;

	PEU_IS_DATA_IN_SIGNED_DATA_AVAILABLE
								IsDataInSignedDataAvailable;
	PEU_IS_DATA_IN_SIGNED_FILE_AVAILABLE
								IsDataInSignedFileAvailable;
	PEU_GET_DATA_FROM_SIGNED_DATA
								GetDataFromSignedData;
	PEU_GET_DATA_FROM_SIGNED_FILE
								GetDataFromSignedFile;

	PEU_GET_CERTIFICATES_FROM_LDAP_BY_EDRPOU_CODE
								GetCertificatesFromLDAPByEDRPOUCode;

	PEU_PROTECT_DATA_BY_PASSWORD
								ProtectDataByPassword;
	PEU_UNPROTECT_DATA_BY_PASSWORD
								UnprotectDataByPassword;

	PEU_FREE_TIME_INFO			FreeTimeInfo;
	PEU_GET_SIGN_TIME_INFO		GetSignTimeInfo;
	PEU_GET_FILE_SIGN_TIME_INFO	GetFileSignTimeInfo;

	PEU_VERIFY_HASH_ON_TIME		VerifyHashOnTime;
	PEU_VERIFY_DATA_ON_TIME		VerifyDataOnTime;
	PEU_VERIFY_DATA_INTERNAL_ON_TIME
								VerifyDataInternalOnTime;
	PEU_VERIFY_DATA_ON_TIME_BEGIN
								VerifyDataOnTimeBegin;
	PEU_VERIFY_FILE_ON_TIME		VerifyFileOnTime;

	PEU_VERIFY_HASH_ON_TIME_EX	VerifyHashOnTimeEx;
	PEU_VERIFY_DATA_ON_TIME_EX	VerifyDataOnTimeEx;
	PEU_VERIFY_DATA_INTERNAL_ON_TIME_EX
								VerifyDataInternalOnTimeEx;
	PEU_VERIFY_DATA_ON_TIME_BEGIN_EX
								VerifyDataOnTimeBeginEx;
	PEU_VERIFY_FILE_ON_TIME_EX	VerifyFileOnTimeEx;

	PEU_CTX_ENUM_PRIVATE_KEY_INFO
								CtxEnumPrivateKeyInfo;
	PEU_CTX_EXPORT_PRIVATE_KEY_CONTAINER
								CtxExportPrivateKeyContainer;
	PEU_CTX_EXPORT_PRIVATE_KEY_PFX_CONTAINER
								CtxExportPrivateKeyPFXContainer;
	PEU_CTX_EXPORT_PRIVATE_KEY_CONTAINER_FILE
								CtxExportPrivateKeyContainerFile;
	PEU_CTX_EXPORT_PRIVATE_KEY_PFX_CONTAINER_FILE
								CtxExportPrivateKeyPFXContainerFile;
	PEU_CTX_GET_CERTIFICATE_FROM_PRIVATE_KEY
								CtxGetCertificateFromPrivateKey;

	PEU_RAW_ENVELOP_DATA		RawEnvelopData;
	PEU_RAW_DEVELOP_DATA		RawDevelopData;

	PEU_RAW_VERIFY_DATA_EX		RawVerifyDataEx;

	PEU_ENVELOP_DATA_RSA_EX		EnvelopDataRSAEx;
	PEU_ENVELOP_DATA_RSA		EnvelopDataRSA;
	PEU_ENVELOP_FILE_RSA_EX		EnvelopFileRSAEx;
	PEU_ENVELOP_FILE_RSA		EnvelopFileRSA;
	PEU_GET_RECEIVERS_CERTIFICATES_RSA
								GetReceiversCertificatesRSA;
	PEU_ENVELOP_DATA_TO_RECIPIENTS_RSA
								EnvelopDataToRecipientsRSA;
	PEU_ENVELOP_FILE_TO_RECIPIENTS_RSA
								EnvelopFileToRecipientsRSA;

	PEU_REMOVE_SIGN				RemoveSign;
	PEU_REMOVE_SIGN_FILE		RemoveSignFile;

	PEU_DEV_CTX_ENUM			DevCtxEnum;
	PEU_DEV_CTX_OPEN			DevCtxOpen;
	PEU_DEV_CTX_ENUM_VIRTUAL	DevCtxEnumVirtual;
	PEU_DEV_CTX_OPEN_VIRTUAL	DevCtxOpenVirtual;
	PEU_DEV_CTX_CLOSE			DevCtxClose;
	PEU_DEV_CTX_BEGIN_PERSONALIZATION
								DevCtxBeginPersonalization;
	PEU_DEV_CTX_CONTINUE_PERSONALIZATION
								DevCtxContinuePersonalization;
	PEU_DEV_CTX_END_PERSONALIZATION
								DevCtxEndPersonalization;
	PEU_DEV_CTX_GET_DATA		DevCtxGetData;
	PEU_DEV_CTX_UPDATE_DATA		DevCtxUpdateData;
	PEU_DEV_CTX_SIGN_DATA		DevCtxSignData;
	PEU_DEV_CTX_CHANGE_PASSWORD	DevCtxChangePassword;
	PEU_DEV_CTX_UPDATE_SYSTEM_PUBLIC_KEY
								DevCtxUpdateSystemPublicKey;
	PEU_DEV_CTX_SIGN_SYSTEM_PUBLIC_KEY
								DevCtxSignSystemPublicKey;

	PEU_GET_RECEIVERS_CERTIFICATES_EX
								GetReceiversCertificatesEx;

	PEU_APPEND_TRANSPORT_HEADER	AppendTransportHeader;
	PEU_PARSE_TRANSPORT_HEADER	ParseTransportHeader;
	PEU_APPEND_CRYPTO_HEADER	AppendCryptoHeader;
	PEU_PARSE_CRYPTO_HEADER		ParseCryptoHeader;

	PEU_ENVELOP_DATA_TO_RECIPIENTS_OFFLINE
								EnvelopDataToRecipientsOffline;

	PEU_DEV_CTX_GENERATE_PRIVATE_KEY
								DevCtxGeneratePrivateKey;

	PEU_GENERATE_PRNG_SEQUENCE
								GeneratePRNGSequence;

	PEU_SET_SETTINGS_FILE_PATH_EX
								SetSettingsFilePathEx;

	PEU_CHANGE_OWN_CERTIFICATES_STATUS
								ChangeOwnCertificatesStatus;
	PEU_CTX_CHANGE_OWN_CERTIFICATES_STATUS
								CtxChangeOwnCertificatesStatus;

	PEU_GET_CERTIFICATES_BY_NBU_CODE_AND_CMP
								GetCertificatesByNBUCodeAndCMP;

	PEU_ENUM_CERTIFICATES_EX	EnumCertificatesEx;

	PEU_MAKE_NEW_CERTIFICATE	MakeNewCertificate;

	PEU_CREATE_SIGNER_BEGIN		CreateSignerBegin;
	PEU_CREATE_SIGNER_END		CreateSignerEnd;

	PEU_CLIENT_DYNAMIC_KEY_SESSION_LOAD
								ClientDynamicKeySessionLoad;

	PEU_DEV_CTX_OPEN_IDCARD		DevCtxOpenIDCard;
	PEU_DEV_CTX_CHANGE_IDCARD_PASSWORDS
								DevCtxChangeIDCardPasswords;
	PEU_DEV_CTX_AUTHENTICATE_IDCARD
								DevCtxAuthenticateIDCard;
	PEU_DEV_CTX_VERIFY_IDCARD_DATA
								DevCtxVerifyIDCardData;
	PEU_DEV_CTX_UPDATE_IDCARD_DATA
								DevCtxUpdateIDCardData;
	PEU_DEV_CTX_ENUM_IDCARD_DATA
								DevCtxEnumIDCardData;

	PEU_ENVELOP_DATA_WITH_SETTINGS
								EnvelopDataWithSettings;
	PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_SETTINGS
								EnvelopDataToRecipientsWithSettings;

	PEU_SHOW_SECURE_CONFIRM_DIALOG
								ShowSecureConfirmDialog;

	PEU_CTX_CLIENT_SESSION_CREATE_STEP1
								CtxClientSessionCreateStep1;
	PEU_CTX_SERVER_SESSION_CREATE_STEP1
								CtxServerSessionCreateStep1;
	PEU_CTX_SESSION_LOAD		CtxSessionLoad;
	PEU_CTX_SERVER_DYNAMIC_KEY_SESSION_CREATE
								CtxServerDynamicKeySessionCreate;

	PEU_CTX_GET_SIGN_VALUE		CtxGetSignValue;
	PEU_APPEND_SIGNER_UNSIGNED_ATTRIBUTE
								AppendSignerUnsignedAttribute;
	PEU_CHECK_CERTIFICATE_BY_OCSP
								CheckCertificateByOCSP;
	PEU_GET_OCSP_RESPONSE		GetOCSPResponse;
	PEU_CHECK_OCSP_RESPONSE		CheckOCSPResponse;
	PEU_CHECK_CERTIFICATE_BY_OCSP_RESPONSE
								CheckCertificateByOCSPResponse;
	PEU_CREATE_REVOCATION_INFO_ATTRIBUTES
								CreateRevocationInfoAttributes;
	PEU_GET_CERTIFICATE_CHAIN	GetCertificateChain;
	PEU_CREATE_CA_CERTIFICATE_INFO_ATTRIBUTES
								CreateCACertificateInfoAttributes;
	PEU_GET_TSP					GetTSP;
	PEU_CHECK_TSP				CheckTSP;
	PEU_CTX_CLIENT_SESSION_CREATE
								CtxClientSessionCreate;
	PEU_CTX_SERVER_SESSION_CREATE
								CtxServerSessionCreate;

	PEU_CTX_IS_NAMED_PRIVATE_KEY_EXISTS
								CtxIsNamedPrivateKeyExists;
	PEU_CTX_GENERATE_NAMED_PRIVATE_KEY
								CtxGenerateNamedPrivateKey;
	PEU_CTX_READ_NAMED_PRIVATE_KEY
								CtxReadNamedPrivateKey;
	PEU_CTX_DESTROY_NAMED_PRIVATE_KEY
								CtxDestroyNamedPrivateKey;

	PEU_CTX_CHANGE_NAMED_PRIVATE_KEY_PASSWORD
								CtxChangeNamedPrivateKeyPassword;
	PEU_GET_TSP_BY_ACCESS_INFO	GetTSPByAccessInfo;

	PEU_GET_CERTIFICATE_BY_FINGERPRINT
								GetCertificateByFingerprint;
	PEU_FREE_CERTIFICATES		FreeCertificates;
	PEU_GET_CERTIFICATES_BY_EDRPOU_AND_DRFO_CODE
								GetCertificatesByEDRPOUAndDRFOCode;

	PEU_SET_OCSP_RESPONSE_EXPIRE_TIME
								SetOCSPResponseExpireTime;
	PEU_GET_OCSP_RESPONSE_BY_ACCESS_INFO
								GetOCSPResponseByAccessInfo;

	PEU_DELETE_CERTIFICATE		DeleteCertificate;

	PEU_SET_KEY_MEDIA_USER_PASSWORD
								SetKeyMediaUserPassword;

	PEU_CHECK_DATA_STRUCT		CheckDataStruct;
	PEU_CHECK_FILE_STRUCT		CheckFileStruct;

	PEU_DEV_CTX_ENUM_IDCARD_DATA_CHANGE_DATE
								DevCtxEnumIDCardDataChangeDate;

	PEU_GET_DATA_HASH_FROM_SIGNED_DATA
								GetDataHashFromSignedData;
	PEU_GET_DATA_HASH_FROM_SIGNED_FILE
								GetDataHashFromSignedFile;

	PEU_DEV_CTX_VERIFY_IDCARD_SECURITY_OBJECT_DOCUMENT
								DevCtxVerifyIDCardSecurityObjectDocument;

	PEU_VERIFY_DATA_WITH_PARAMS	VerifyDataWithParams;
	PEU_VERIFY_DATA_INTERNAL_WITH_PARAMS
								VerifyDataInternalWithParams;

	PEU_CTX_GET_NAMED_PRIVATE_KEY_INFO
								CtxGetNamedPrivateKeyInfo;

	PEU_GET_CERTIFICATE_BY_KEY_INFO_EX
								GetCertificateByKeyInfoEx;

	PEU_SHOW_CERTIFICATE		ShowCertificate;

	PEU_APPEND_FILE_TRANSPORT_HEADER
								AppendFileTransportHeader;
	PEU_PARSE_FILE_TRANSPORT_HEADER
								ParseFileTransportHeader;
	PEU_APPEND_FILE_CRYPTO_HEADER
								AppendFileCryptoHeader;
	PEU_PARSE_FILE_CRYPTO_HEADER
								ParseFileCryptoHeader;

	PEU_FREE_KEY_MEDIA_DEVICE_INFO
								FreeKeyMediaDeviceInfo;
	PEU_GET_KEY_MEDIA_DEVICE_INFO
								GetKeyMediaDeviceInfo;
	PEU_CTX_ENUM_NAMED_PRIVATE_KEYS
								CtxEnumNamedPrivateKeys;

	PEU_DEV_CTX_INTERNAL_AUTHENTICATE_IDCARD
								DevCtxInternalAuthenticateIDCard;

	PEU_RECOVER_KEY_INFO		RecoverKeyInfo;
	PEU_RECOVER_KEY_INFO_BINARY	RecoverKeyInfoBinary;
	PEU_RECOVER_KEY_INFO_FILE	RecoverKeyInfoFile;
	PEU_READ_AND_RECOVER_PRIVATE_KEY_BINARY
								ReadAndRecoverPrivateKeyBinary;

	PEU_SSERVER_CLIENT_SIGN_HASH
								SServerClientSignHash;
	PEU_SSERVER_CLIENT_SIGN_FILE
								SServerClientSignFile;

	PEU_SSERVER_CLIENT_GENERATE_PRIVATE_KEY
								SServerClientGeneratePrivateKey;

	PEU_SIGN_HASH_RSA			SignHashRSA;

	PEU_GET_SIGNER				GetSigner;
	PEU_GET_FILE_SIGNER			GetFileSigner;
	PEU_APPEND_VALIDATION_DATA_TO_SIGNER
								AppendValidationDataToSigner;

	PEU_GET_HOST_INFO			GetHostInfo;
	PEU_IS_REMOTELY_CONTROLLED	IsRemotelyControlled;

	PEU_SSERVER_CLIENT_SIGN_HASH_ASYNC
								SServerClientSignHashAsync;
	PEU_SSERVER_CLIENT_CHECK_SIGN_HASH_STATUS
								SServerClientCheckSignHashStatus;
	PEU_SSERVER_CLIENT_GENERATE_PRIVATE_KEY_ASYNC
								SServerClientGeneratePrivateKeyAsync;
	PEU_SSERVER_CLIENT_CHECK_GENERATE_PRIVATE_KEY_STATUS
								SServerClientCheckGeneratePrivateKeyStatus;

	PEU_ADD_PAYMENT				AddPayment;

	PEU_MAKE_NEW_OWN_CERTIFICATE
								MakeNewOwnCertificate;

	PEU_FREE_EUSER_PARAMS		FreeEUserParams;
	PEU_GET_OWN_EUSER_PARAMS	GetOwnEUserParams;
	PEU_MODIFY_OWN_EUSER_PARAMS	ModifyOwnEUserParams;

	PEU_CTX_FREE_EUSER_PARAMS	CtxFreeEUserParams;
	PEU_CTX_GET_OWN_EUSER_PARAMS
								CtxGetOwnEUserParams;
	PEU_CTX_MODIFY_OWN_EUSER_PARAMS	
								CtxModifyOwnEUserParams;

	PEU_CTX_RAW_SIGN_DATA		CtxRawSignData;
	PEU_CTX_RAW_SIGN_HASH		CtxRawSignHash;

	PEU_GET_CERTIFICATE_BY_KEY_INFO_WITH_SETTINGS
								GetCertificateByKeyInfoWithSettings;

	PEU_CTX_ENVELOP_DATA_WITH_DYNAMIC_KEY
								CtxEnvelopDataWithDynamicKey;
	PEU_CTX_ENVELOP_FILE_WITH_DYNAMIC_KEY
								CtxEnvelopFileWithDynamicKey;

	PEU_CTX_CREATE_EMPTY_SIGN_FILE
								CtxCreateEmptySignFile;
	PEU_CTX_APPEND_SIGNER_FILE
								CtxAppendSignerFile;

	PEU_CTX_MAKE_NEW_OWN_CERTIFICATE
								CtxMakeNewOwnCertificate;

	PEU_SIGN_DATA_ECDSA			SignDataECDSA;

	PEU_GET_HMAC_DATA_SHA		GetHMACDataSHA;
	PEU_CHECK_HMAC_DATA_SHA		CheckHMACDataSHA;

	PEU_CTX_MAKE_NEW_NAMED_CERTIFICATE
								CtxMakeNewNamedCertificate;

	PEU_GET_CERTIFICATES		GetCertificates;
	PEU_SAVE_CERTIFICATES_EX	SaveCertificatesEx;
	PEU_GET_SIGN_TYPE			GetSignType;
	PEU_GET_FILE_SIGN_TYPE		GetFileSignType;

	PEU_CTX_OPEN_PRIVATE_KEY	CtxOpenPrivateKey;
	PEU_CTX_PREPARE_NAMED_PRIVATE_KEY
								CtxPrepareNamedPrivateKey;

	PEU_CTX_GENERATE_NAMED_PRIVATE_KEY_EX
								CtxGenerateNamedPrivateKeyEx;

	PEU_APPEND_VALIDATION_DATA_TO_SIGNER_EX
								AppendValidationDataToSignerEx;

	PEU_SSERVER_CLIENT_SIGN_HASHES_ASYNC
								SServerClientSignHashesAsync;
	PEU_SSERVER_CLIENT_CHECK_SIGN_HASHES_STATUS
								SServerClientCheckSignHashesStatus;
	PEU_SSERVER_CLIENT_FREE_SIGN_HASHES_RESULTS
								SServerClientFreeSignHashesResults;

	PEU_CTX_CREATE_AUTH_DATA	CtxCreateAuthData;
	PEU_CTX_CHECK_AUTH_DATA		CtxCheckAuthData;

	PEU_APPEND_RECIPIENT		AppendRecipient;
	PEU_GET_RECIPIENT			GetRecipient;
	PEU_REMOVE_RECIPIENT		RemoveRecipient;
	PEU_PASSWORD_RECIPIENT_DEVELOP_DATA
								PasswordRecipientDevelopData;
	PEU_CTX_MAKE_PASSWORD_RECIPIENT
								CtxMakePasswordRecipient;
	PEU_CTX_MAKE_OTHER_RECIPIENT
								CtxMakeOtherRecipient;

	PEU_CTX_PARSE_CERTIFICATE_EX
								CtxParseCertificateEx;
	PEU_CTX_GET_CR_INFO			CtxGetCRInfo;
	PEU_CTX_FREE_CR_INFO		CtxFreeCRInfo;

	PEU_CTX_MAKE_DEVICE_CERTIFICATE
								CtxMakeDeviceCertificate;

	PEU_DEV_CTX_OPEN_IDCARD_VIRTUAL
								DevCtxOpenIDCardVirtual;
	PEU_DEV_CTX_GET_IDCARD_AA_CREDENTIALS
								DevCtxGetIDCardAACredentials;
	PEU_DEV_CTX_VERIFY_IDCARD_AA_CREDENTIALS
								DevCtxVerifyIDCardAACredentials;
	PEU_DEV_CTX_ENUM_IDCARD_SIGNED_DATA
								DevCtxEnumIDCardSignedData;
	PEU_DEV_CTX_VALIDATE_IDCARD_DATA_GROUP
								DevCtxValidateIDCardDataGroup;
	PEU_DEV_CTX_VERIFY_IDCARD_SECURITY_OBJECT_DOCUMENT_DATA
								DevCtxVerifyIDCardSecurityObjectDocumentData;
	PEU_DEV_CTX_GET_IDCARD_BASIC_USER_INFO
								DevCtxGetIDCardBasicUserInfo;
	PEU_DEV_CTX_GET_IDCARD_BASIC_INFO
								DevCtxGetIDCardBasicInfo;
	PEU_DEV_CTX_GET_IDCARD_USER_FULL_NAME
								DevCtxGetIDCardUserFullName;
	PEU_DEV_CTX_GET_IDCARD_USER_DRFO_CODE
								DevCtxGetIDCardUserDRFOCode;
	PEU_DEV_CTX_GET_IDCARD_ADDITIONAL_INFO
								DevCtxGetIDCardAdditionalInfo;

	PEU_CTX_FREE_COUPLE_SIGN	CtxFreeCoupleSign;
	PEU_CTX_CLIENT_CREATE_COUPLE_SIGN_STEP1
								CtxClientCreateCoupleSignStep1;
	PEU_CTX_SERVER_CREATE_COUPLE_SIGN_STEP1
								CtxServerCreateCoupleSignStep1;
	PEU_CTX_CLIENT_CREATE_COUPLE_SIGN_STEP2
								CtxClientCreateCoupleSignStep2;
	PEU_CTX_SERVER_CREATE_COUPLE_SIGN_STEP2
								CtxServerCreateCoupleSignStep2;
	PEU_CREATE_COUPLE_CR_BEGIN	CreateCoupleCRBegin;
	PEU_CREATE_CR_END			CreateCREnd;

	PEU_CREATE_SIGNER_EX		CreateSignerEx;
	PEU_CTX_CREATE_SIGNER_EX	CtxCreateSignerEx;

	PEU_DEV_CTX_GET_IDCARD_VERIFY_SECURITY_OBJECT_DOCUMENT_ERROR
								DevCtxGetIDCardLastVerifySecurityObjectDocumentError;

	PEU_GENERATE_PRIVATE_KEY_2	GeneratePrivateKey2;
	PEU_CTX_GENERATE_NAMED_PRIVATE_KEY_2
								CtxGenerateNamedPrivateKey2;

	PEU_DEV_CTX_OPEN_IDCARD_EX	DevCtxOpenIDCardEx;
	PEU_DEV_CTX_ACTIVATE_IDCARD_ESIGN	DevCtxActivateIDCardESign;

	PEU_DEV_CTX_GET_IDCARD_VERSION	DevCtxGetIDCardVersion;

	PEU_DEV_CTX_GET_IDCARD_VERSION_FROM_DEVICE
								DevCtxGetIDCardVersionFromDevice;

	PEU_ASIC_GET_ASIC_TYPE		ASiCGetASiCType;
	PEU_ASIC_GET_SIGN_TYPE		ASiCGetSignType;
	PEU_ASIC_GET_SINGS_COUNT	ASiCGetSignsCount;
	PEU_ASIC_GET_SIGNER_INFO	ASiCGetSignerInfo;
	PEU_ASIC_GET_SIGN_TIME_INFO	ASiCGetSignTimeInfo;
	PEU_ASIC_GET_SIGN_REFERENCES
								ASiCGetSignReferences;
	PEU_ASIC_GET_REFERENCE		ASiCGetReference;
	PEU_ASIC_SIGN_DATA			ASiCSignData;
	PEU_ASIC_VERIFY_DATA		ASiCVerifyData;
	PEU_CTX_ASIC_SIGN_DATA		CtxASiCSignData;

	PEU_CTX_ASIC_GET_SIGNER_INFO
								CtxASiCGetSignerInfo;
	PEU_ASIC_GET_SIGN_LEVEL		ASiCGetSignLevel;

	PEU_PDF_GET_SIGN_TYPE		PDFGetSignType;
	PEU_PDF_GET_SINGS_COUNT		PDFGetSignsCount;
	PEU_PDF_GET_SIGNER_INFO		PDFGetSignerInfo;
	PEU_CTX_PDF_GET_SIGNER_INFO	CtxPDFGetSignerInfo;
	PEU_PDF_GET_SIGN_TIME_INFO	PDFGetSignTimeInfo;
	PEU_PDF_SIGN_DATA			PDFSignData;
	PEU_PDF_VERIFY_DATA			PDFVerifyData;
	PEU_CTX_PDF_SIGN_DATA		CtxPDFSignData;

	PEU_COSE_SIGN_DATA			COSESignData;
	PEU_COSE_SIGN_FILE			COSESignFile;
	PEU_COSE_VERIFY_DATA		COSEVerifyData;
	PEU_COSE_VERIFY_FILE		COSEVerifyFile;
	PEU_COSE_GET_KEY_ID_FROM_SIGNED_DATA
								COSEGetKeyIDFromSignedData;
	PEU_COSE_GET_KEY_ID_FROM_SIGNED_FILE
								COSEGetKeyIDFromSignedFile;
	PEU_CTX_COSE_SIGN_DATA		CtxCOSESignData;
	PEU_CTX_COSE_SIGN_FILE		CtxCOSESignFile;

	PEU_BASE45_ENCODE			BASE45Encode;
	PEU_BASE45_DECODE			BASE45Decode;

	PEU_COMPRESS_DATA			CompressData;
	PEU_UNCOMPRESS_DATA			UncompressData;
	PEU_COMPRESS_FILE			CompressFile;
	PEU_UNCOMPRESS_FILE			UncompressFile;

	PEU_ASIC_IS_ALL_CONTENT_COVERED
								ASiCIsAllContentCovered;

	PEU_XADES_GET_TYPE			XAdESGetType;
	PEU_XADES_GET_SINGS_COUNT	XAdESGetSignsCount;
	PEU_XADES_GET_SIGN_LEVEL	XAdESGetSignLevel;
	PEU_XADES_GET_SIGNER_INFO	XAdESGetSignerInfo;
	PEU_XADES_GET_SIGN_TIME_INFO
								XAdESGetSignTimeInfo;
	PEU_XADES_GET_SIGN_REFERENCES
								XAdESGetSignReferences;
	PEU_XADES_GET_REFERENCE		XAdESGetReference;
	PEU_XADES_SIGN_DATA			XAdESSignData;
	PEU_XADES_VERIFY_DATA		XAdESVerifyData;
	PEU_CTX_XADES_SIGN_DATA		CtxXAdESSignData;
	PEU_CTX_XADES_GET_SIGNER_INFO
								CtxXAdESGetSignerInfo;

	PEU_GET_MAC_DATA			GetMACData;

	PEU_CTX_GENERATE_NAMED_PRIVATE_KEY_2_EX
								CtxGenerateNamedPrivateKey2Ex;
	PEU_CTX_DESTROY_NAMED_PRIVATE_KEY_EX
								CtxDestroyNamedPrivateKeyEx;

	PEU_CTX_ENVELOP_DATA_RSA
								CtxEnvelopDataRSA;

	PEU_CLIENTS_CTX_OPEN		ClientsCtxOpen;
	PEU_CLIENTS_CTX_CLOSE		ClientsCtxClose;
	PEU_CLIENTS_CTX_ENUM_CLIENTS
								ClientsCtxEnumClients;
	PEU_CLIENTS_CTX_ADD_CLIENT	ClientsCtxAddClient;
	PEU_CLIENTS_CTX_CHANGE_CLIENT
								ClientsCtxChangeClient;
	PEU_CLIENTS_CTX_REMOVE_CLIENT
								ClientsCtxRemoveClient;

	PEU_GET_CERT_SUBJECT_PUBLIC_KEY_INFO
								GetCertSubjectPublicKeyInfo;
	PEU_GET_CERT_REQUEST_SUBJECT_PUBLIC_KEY_INFO
								GetCertRequestSubjectPublicKeyInfo;
	PEU_GET_SUBJECT_PUBLIC_KEY_INFO_ID
								GetSubjectPublicKeyInfoID;

	PEU_ASIC_APPEND_SIGN		ASiCAppendSign;
	PEU_CTX_ASIC_APPEND_SIGN	CtxASiCAppendSign;

	PEU_CTX_MAKE_NEW_OWN_CERTIFICATE_WITH_CR
								CtxMakeNewOwnCertificateWithCR;

	PEU_CTX_GET_PRIVATE_KEY_INFO
								CtxGetPrivateKeyInfo;

	PEU_CTX_SERVER_CREATE_COUPLE_CR_BEGIN
								CtxServerCreateCoupleCRBegin;

	PEU_CLIENT_RAW_MULTI_SESSION_CREATE
								ClientRawMultiSessionCreate;
	PEU_SERVER_RAW_MULTI_SESSION_CREATE
								ServerRawMultiSessionCreate;
	PEU_RAW_MULTI_SESSION_ADD_CLIENTS
								RawMultiSessionAddClients;

	PEU_GET_TSL_SETTINGS		GetTSLSettings;
	PEU_SET_TSL_SETTINGS		SetTSLSettings;
	PEU_SAVE_TSL				SaveTSL;

	PEU_GET_LOG_SETTINGS		GetLogSettings;
	PEU_SET_LOG_SETTINGS		SetLogSettings;

	PEU_SERVER_SESSION_CREATE_STEP1_EX
								ServerSessionCreateStep1Ex;

	PEU_ENVELOP_DATA_TO_RECIPIENTS_WITH_SETTINGS_EX
								EnvelopDataToRecipientsWithSettingsEx;

	PEU_ASIC_CREATE_EMPTY_SIGN	ASiCCreateEmptySign;
	PEU_ASIC_CREATE_SIGNER_BEGIN
								ASiCCreateSignerBegin;
	PEU_ASIC_CREATE_SIGNER_END	ASiCCreateSignerEnd;
	PEU_DEV_CTX_INTERNAL_AUTHENTICATE_IDCARD_WITH_IGNORING_KEY
								DevCtxInternalAuthenticateIDCardWithIgnoringKey;

	PEU_CTX_ENVELOP_DATA_WITH_SETTINGS
								CtxEnvelopDataWithSettings;

	PEU_CTX_GET_SSERVER_CLIENT_REGISTRATION_TOKEN
								CtxGetSServerClientRegistrationToken;

	PEU_NBU_SIGN_DATA			NBUSignData;
	PEU_NBU_VERIFY_DATA			NBUVerifyData;

	PEU_PDF_CREATE_SIGNER_BEGIN	PDFCreateSignerBegin;
	PEU_PDF_CREATE_SIGNER_END	PDFCreateSignerEnd;

	PEU_CREATE_SIGNER_BEGIN_EX	CreateSignerBeginEx;

	PEU_ALGO_CTX_CREATE			AlgoCtxCreate;
	PEU_ALGO_CTX_GENERATE_KEY	AlgoCtxGenerateKey;
	PEU_ALGO_CTX_SET_KEY		AlgoCtxSetKey;
	PEU_ALGO_CTX_GET_KEY_SIZE	AlgoCtxGetKeySize;
	PEU_ALGO_CTX_GET_KEY		AlgoCtxGetKey;
	PEU_ALGO_CTX_ENCRYPT		AlgoCtxEncrypt;
	PEU_ALGO_CTX_DECRYPT		AlgoCtxDecrypt;
	PEU_ALGO_CTX_GET_DATA_MAC	AlgoCtxGetDataMAC;
	PEU_ALGO_CTX_FREE			AlgoCtxFree;

	PEU_SSERVER_CLIENT_RESET_OPERATION
								SServerClientResetOperation;

	PEU_DEV_CTX_GENERATE_IDCARD_IS_PRIVATE_KEY
								DevCtxGenerateIDCardISPrivateKey;

	PEU_INITIALIZE_CERTIFICATE_STATUS_CACHE
								InitializeCertificateStatusCache;
} EU_INTERFACE, *PEU_INTERFACE;

//=============================================================================

#define EU_LIBRARY_NAME		"euscp.so"

//=============================================================================

int EULoad();

PEU_INTERFACE EUGetInterface();

void EUUnload();

//=============================================================================

#endif // EU_SIGN_CP_H
