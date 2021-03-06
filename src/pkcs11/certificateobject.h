/**
 * SmartCard-HSM PKCS#11 Module
 *
 * Copyright (c) 2013, CardContact Systems GmbH, Minden, Germany
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of CardContact Systems GmbH nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL CardContact Systems GmbH BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @file    certificateobject.h
 * @author  Frank Thater, Andreas Schwier
 * @brief   Functions for certificate objects
 */

#ifndef ___CERTIFICATEOBJECT_H_INC___
#define ___CERTIFICATEOBJECT_H_INC___


#include <pkcs11/p11generic.h>
#include <pkcs11/session.h>
#include <pkcs11/cryptoki.h>
#include <pkcs11/object.h>
#include <common/pkcs15.h>

int createCertificateObject(CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, struct p11Object_t *object);
int populateIssuerSubjectSerial(struct p11Object_t *pObject);
int populateCVCAttributes(struct p11Object_t *pObject);
int getSubjectPublicKeyInfo(struct p11Object_t *pObject, unsigned char **spki);
int decodeModulusExponentFromSPKI(unsigned char *spki, CK_ATTRIBUTE_PTR modulus, CK_ATTRIBUTE_PTR exponent);
int decodeECParamsFromSPKI(unsigned char *spki, CK_ATTRIBUTE_PTR ecparams);
int decodeECPointFromSPKI(unsigned char *spki, CK_ATTRIBUTE_PTR point);
int createCertificateObjectFromP15(struct p15CertificateDescription *p15, unsigned char *cert, size_t certlen, struct p11Object_t **pObject);

#endif /* ___SECRETKEYOBJECT_H_INC___ */
