//
// HtWordType.h
//
// HtWordType:  Wrap some attributes to make is...() type
//              functions and other common functions without having to manage
//              the attributes or the exact attribute combination semantics.
//
// Part of the ht://Dig package   <http://www.htdig.org/>
// Copyright (c) 1999 The ht://Dig Group
// For copyright details, see the file COPYING in your distribution
// or the GNU Public License version 2 or later 
// <http://www.gnu.org/copyleft/gpl.html>
//
// $Id: HtWordType.h,v 1.6 1999/09/24 10:29:03 loic Exp $
//

#ifndef __HtWordType_h
#define __HtWordType_h

#include "htString.h"
#include "Configuration.h"

#include <ctype.h>

//
// Inline friend-functions are used together with an all-statics
// class (name that pattern!) to spare the user from having
// to manage the valid_punctuation and extra_word_characters
// attributes, while in theory still having better runtime
// performance than strchr() + isalnum().
//

class HtWordType
{
public:
  friend int HtIsWordChar(int c);
  friend int HtIsStrictWordChar(int c);
  friend void HtStripPunctuation(String &s);

  // To be called once all attributes and configuration files
  // have been read.
  static void Initialize(Configuration & config);

private:

  // Wrap them up in a struct, so the compiler has a good chance
  // to see the proximity.
  static struct InnerStatics
  {
    String valid_punctuation;     // The same as the attribute.
    String extra_word_characters; // Likewise.
    String other_chars_in_word;   // Attribute "valid_punctuation" plus
                                 // "extra_word_characters".
    char chrtypes[256];          // quick lookup table for types
  } statics;

  // These methods are not supposed to be implemented (or accessed).
  HtWordType();
  HtWordType(const HtWordType &);
  void operator=(const HtWordType &);
};

// Bits to set in chrtypes[]:
#define HtWt_Alpha	0x01
#define HtWt_Digit	0x02
#define HtWt_Extra	0x04
#define HtWt_ValidPunct	0x08

// One for characters that when put together are a word
// (including punctuation).
inline int
HtIsWordChar(int c)
{
  return (HtWordType::statics.chrtypes[(unsigned char)c] & (HtWt_Alpha|HtWt_Digit|HtWt_Extra|HtWt_ValidPunct)) != 0;
}

// Similar, but no punctuation characters.
inline int
HtIsStrictWordChar(int c)
{
  return (HtWordType::statics.chrtypes[(unsigned char)c] & (HtWt_Alpha|HtWt_Digit|HtWt_Extra)) != 0;
}

// Let caller get rid of getting and holding a configuration parameter.
inline void
HtStripPunctuation(String &s)
{
  s.remove(HtWordType::statics.valid_punctuation);
}

#endif /* __HtWordType_h */
