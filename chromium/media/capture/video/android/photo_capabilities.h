// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CAPTURE_VIDEO_ANDROID_PHOTO_CAPABILITIES_H_
#define MEDIA_CAPTURE_VIDEO_ANDROID_PHOTO_CAPABILITIES_H_

#include <jni.h>
#include <string>

#include "base/android/scoped_java_ref.h"

namespace media {

class PhotoCapabilities {
 public:
  // Focus modes from Java side, equivalent to media.mojom::MeteringMode, except
  // NOT_SET, which is used to signify absence of setting configuration.
  // A Java counterpart will be generated for this enum.
  // GENERATED_JAVA_ENUM_PACKAGE: org.chromium.media
  enum class AndroidMeteringMode {
    NOT_SET,
    UNAVAILABLE,
    FIXED,
    SINGLE_SHOT,
    CONTINUOUS,
  };

  explicit PhotoCapabilities(base::android::ScopedJavaLocalRef<jobject> object);
  ~PhotoCapabilities();

  int getMinIso() const;
  int getMaxIso() const;
  int getCurrentIso() const;
  int getMinHeight() const;
  int getMaxHeight() const;
  int getCurrentHeight() const;
  int getMinWidth() const;
  int getMaxWidth() const;
  int getCurrentWidth() const;
  int getMinZoom() const;
  int getMaxZoom() const;
  int getCurrentZoom() const;
  AndroidMeteringMode getFocusMode() const;
  AndroidMeteringMode getExposureMode() const;

 private:
  const base::android::ScopedJavaLocalRef<jobject> object_;
};

}  // namespace media

#endif  // MEDIA_CAPTURE_VIDEO_ANDROID_PHOTO_CAPABILITIES_H_