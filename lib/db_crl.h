/* vi: set sw=4 ts=4:
 *
 * Copyright (C) 2001 - 2007 Christian Hohnstaedt.
 *
 * All rights reserved.
 */

#ifndef __DB_CRL_H
#define __DB_CRL_H

#include "db_x509super.h"
#include "pki_crl.h"

class db_crl: public db_x509name
{
		Q_OBJECT
	protected:
		dbheaderList getHeaders();
	public:
		db_crl();
		pki_base *newPKI(enum pki_type type);
		void revokeCerts(pki_crl *crl);
		void inToCont(pki_base *pki);
		pki_base *insert(pki_base *item);
		void removeSigner(pki_base *signer);
		void updateCertView();
		pki_crl *newCrl(const crljob &crljob);
		void exportItems(const QModelIndexList &indexes,
			const pki_export *xport, XFile &file) const;
};
#endif
