// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_CRYPTAUTH_FAKE_CRYPTAUTH_GCM_MANAGER_H_
#define COMPONENTS_CRYPTAUTH_FAKE_CRYPTAUTH_GCM_MANAGER_H_

#include "base/macros.h"
#include "base/observer_list.h"
#include "components/cryptauth/cryptauth_gcm_manager.h"

namespace cryptauth {

// CryptAuthGCMManager implementation for testing purposes.
class FakeCryptAuthGCMManager : public CryptAuthGCMManager {
 public:
  // Creates the instance:
  // |registration_id|: The GCM registration id from a previous successful
  //     enrollment. Pass in an empty |registration_id| to simulate never having
  //     registered successfully.
  explicit FakeCryptAuthGCMManager(const std::string& registration_id);
  ~FakeCryptAuthGCMManager() override;

  bool has_started_listening() { return has_started_listening_; }
  bool registration_in_progress() { return registration_in_progress_; }

  void set_registration_id(const std::string& registration_id) {
    registration_id_ = registration_id;
  }

  // Simulates completing a GCM registration with the resulting
  // |registration_id|. Passing an empty |registration_id| will simulate a
  // registration failure.
  // A registration attempt must currently be in progress.
  void CompleteRegistration(const std::string& registration_id);

  // Simulates receiving a re-enroll push message from GCM.
  void PushReenrollMessage();

  // Simulates receiving a re-sync push message from GCM.
  void PushResyncMessage();

  // CryptAuthGCMManager:
  void StartListening() override;
  void RegisterWithGCM() override;
  std::string GetRegistrationId() override;
  void AddObserver(Observer* observer) override;
  void RemoveObserver(Observer* observer) override;

 private:
  bool has_started_listening_ = false;
  bool registration_in_progress_ = false;

  // The registration id obtained from the last successful registration.
  std::string registration_id_;

  base::ObserverList<Observer>::Unchecked observers_;

  DISALLOW_COPY_AND_ASSIGN(FakeCryptAuthGCMManager);
};

}  // namespace cryptauth

#endif  // COMPONENTS_CRYPTAUTH_FAKE_CRYPTAUTH_GCM_MANAGER_H_
