// Copyright 2019 David Conran
#include "ir_Argo.h"
#include "IRrecv.h"
#include "IRrecv_test.h"
#include "IRsend.h"
#include "IRsend_test.h"
#include "gtest/gtest.h"


TEST(TestArgoACClass, toCommon) {
  IRArgoAC ac(0);
  ac.setPower(true);
  ac.setMode(kArgoCool);
  ac.setTemp(20);
  ac.setFan(kArgoFan3);
  ac.setMax(true);
  ac.setNight(true);
  // Now test it.
  ASSERT_EQ(decode_type_t::ARGO, ac.toCommon().protocol);
  ASSERT_TRUE(ac.toCommon().power);
  ASSERT_TRUE(ac.toCommon().celsius);
  ASSERT_EQ(20, ac.toCommon().degrees);
  ASSERT_EQ(stdAc::opmode_t::kCool, ac.toCommon().mode);
  ASSERT_EQ(stdAc::fanspeed_t::kMax, ac.toCommon().fanspeed);
  ASSERT_EQ(0, ac.toCommon().sleep);
  ASSERT_TRUE(ac.toCommon().turbo);
  // Unsupported.
  ASSERT_EQ(-1, ac.toCommon().model);
  ASSERT_EQ(stdAc::swingv_t::kOff, ac.toCommon().swingv);
  ASSERT_EQ(stdAc::swingh_t::kOff, ac.toCommon().swingh);
  ASSERT_FALSE(ac.toCommon().econo);
  ASSERT_FALSE(ac.toCommon().light);
  ASSERT_FALSE(ac.toCommon().filter);
  ASSERT_FALSE(ac.toCommon().clean);
  ASSERT_FALSE(ac.toCommon().beep);
  ASSERT_FALSE(ac.toCommon().quiet);
  ASSERT_EQ(-1, ac.toCommon().clock);
}
