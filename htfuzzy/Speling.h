//
// Speling.h
//
// Speling: (sic) Performs elementary (one-off) spelling correction for ht://Dig
//
// Part of the ht://Dig package   <http://www.htdig.org/>
// Copyright (c) 1999 The ht://Dig Group
// For copyright details, see the file COPYING in your distribution
// or the GNU Public License version 2 or later 
// <http://www.gnu.org/copyleft/gpl.html>
//
// $Id: Speling.h,v 1.3 1999/09/24 10:29:02 loic Exp $
//

#ifndef _Speling_h_
#define _Speling_h_

#include "Fuzzy.h"

class Dictionary;
class String;
class List;


class Speling : public Fuzzy
{
public:
    //
    // Construction/Destruction
    //
    Speling(const Configuration& config_arg);
    virtual		~Speling();

    virtual void	getWords(char *word, List &words);
    virtual int		openIndex();

    virtual void	generateKey(char *, String &);
    virtual void	addWord(char *);
	
private:
};

#endif


