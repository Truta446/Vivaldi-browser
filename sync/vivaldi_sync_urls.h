// Copyright (c) 2015 Vivaldi Technologies AS. All rights reserved

#ifndef SYNC_VIVALDI_SYNC_URLS_H_
#define SYNC_VIVALDI_SYNC_URLS_H_

// #define SYNC_HOSTNAME "mirror.viv.osl"
#define SYNC_HOSTNAME "bifrost.vivaldi.com"

#define SYNC_URL_SCHEME "https://"
#define SYNC_SERVERNAME SYNC_HOSTNAME

#define SYNC_NOTIFIER_SERVER1 SYNC_HOSTNAME
#define SYNC_NOTIFIER_SERVER2 SYNC_HOSTNAME
#define SYNC_SECURE_NOTIFIER_SERVER SUPPORTS_SSLTCP
// #define SYNC_SECURE_NOTIFIER_SERVER DOES_NOT_SUPPORT_SSLTCP

#define TEST_SYNC_HOSTNAME "bifrost.vivaldi.com"
#define TEST_SYNC_URL_SCHEME "https://"
#define TEST_SYNC_SERVERNAME TEST_SYNC_HOSTNAME ":4433"
#define TEST_SYNC_URL_WRONG(path) "https://" SYNC_HOSTNAME ":4444" path

#define SYNC_URL(path) SYNC_URL_SCHEME SYNC_SERVERNAME path
#define TEST_SYNC_URL(path) TEST_SYNC_URL_SCHEME TEST_SYNC_SERVERNAME path

#endif  // SYNC_VIVALDI_SYNC_URLS_H_
