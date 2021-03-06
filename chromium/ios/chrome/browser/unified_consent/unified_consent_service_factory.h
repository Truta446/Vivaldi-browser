// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IOS_CHROME_BROWSER_UNIFIED_CONSENT_UNIFIED_CONSENT_SERVICE_FACTORY_H_
#define IOS_CHROME_BROWSER_UNIFIED_CONSENT_UNIFIED_CONSENT_SERVICE_FACTORY_H_

#include "base/memory/singleton.h"
#include "components/keyed_service/ios/browser_state_keyed_service_factory.h"

namespace unified_consent {
class UnifiedConsentService;
}
namespace ios {
class ChromeBrowserState;
}

class UnifiedConsentServiceFactory : public BrowserStateKeyedServiceFactory {
 public:
  static unified_consent::UnifiedConsentService* GetForBrowserState(
      ios::ChromeBrowserState* browser_state);

  static unified_consent::UnifiedConsentService* GetForBrowserStateIfExists(
      ios::ChromeBrowserState* browser_state);

  static UnifiedConsentServiceFactory* GetInstance();

 private:
  friend struct base::DefaultSingletonTraits<UnifiedConsentServiceFactory>;

  UnifiedConsentServiceFactory();
  ~UnifiedConsentServiceFactory() override;

  // BrowserStateKeyedServiceFactory implementation.
  std::unique_ptr<KeyedService> BuildServiceInstanceFor(
      web::BrowserState* context) const override;

  DISALLOW_COPY_AND_ASSIGN(UnifiedConsentServiceFactory);
};

#endif  // IOS_CHROME_BROWSER_UNIFIED_CONSENT_UNIFIED_CONSENT_SERVICE_FACTORY_H_
