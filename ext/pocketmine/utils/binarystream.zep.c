
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "zval_ref.h"


/**
 * This file is part of RapidPM.
 * 
 * RapidPM is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * RapidPM is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with RapidPM.  If not, see <https://www.gnu.org/licenses/>.
 *
*/
ZEPHIR_INIT_CLASS(Pocketmine_Utils_BinaryStream) {

	ZEPHIR_REGISTER_CLASS(Pocketmine\\Utils, BinaryStream, pocketmine, utils_binarystream, pocketmine_utils_binarystream_method_entry, 0);

	/** @var long  */
	zend_declare_property_null(pocketmine_utils_binarystream_ce, SL("offset"), ZEND_ACC_PUBLIC);

	/** @var string */
	zend_declare_property_null(pocketmine_utils_binarystream_ce, SL("buffer"), ZEND_ACC_PUBLIC);

	return SUCCESS;

}

/**
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getOffset) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "offset");

}

/**
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getBuffer) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "buffer");

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset;
	zval *buffer_param = NULL, *offset_param = NULL, _0;
	zval buffer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&buffer);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &buffer_param, &offset_param);

	if (!buffer_param) {
		ZEPHIR_INIT_VAR(&buffer);
		ZVAL_STRING(&buffer, "");
	} else {
		zephir_get_strval(&buffer, buffer_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	zephir_update_property_zval(this_ptr, SL("buffer"), &buffer);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval(this_ptr, SL("offset"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, setOffset) {

	zval *offset_param = NULL, _0;
	long offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &offset_param);

	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval(this_ptr, SL("offset"), &_0);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, reset) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("buffer"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(this_ptr, SL("offset"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Rewinds the stream pointer to the start.
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, rewind) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("offset"), &_0);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, setBuffer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	long offset;
	zval *buffer_param = NULL, *offset_param = NULL, _0;
	zval buffer;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&buffer);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &buffer_param, &offset_param);

	if (!buffer_param) {
		ZEPHIR_INIT_VAR(&buffer);
		ZVAL_STRING(&buffer, "");
	} else {
		zephir_get_strval(&buffer, buffer_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	zephir_update_property_zval(this_ptr, SL("buffer"), &buffer);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval(this_ptr, SL("offset"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param int $len
 *
 * @return string
 *
 * @throws BinaryDataException if there are not enough bytes left in the buffer
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, remaining, _0, _1, _9, _10, _11, _12, _13, _2$$5, _3$$5, _4$$5, _5$$6, _6$$6, _7$$6, _8$$6;
	long len;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&remaining);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (len == 0) {
		RETURN_MM_STRING("");
	}
	if (len < 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Length must be positive", "pocketmine/utils/binarystream.zep", 74);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&remaining);
	ZVAL_LONG(&remaining, (zephir_fast_strlen_ev(&_0) - zephir_get_numberval(&_1)));
	if (ZEPHIR_LT_LONG(&remaining, len)) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, pocketmine_utils_binarydataexception_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_LONG(&_3$$5, len);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SVSV(&_4$$5, "Not enough bytes left in buffer: need ", &_3$$5, ", have ", &remaining);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 22, &_4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "pocketmine/utils/binarystream.zep", 79);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (len == 1) {
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("offset")));
		zephir_read_property(&_5$$6, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$6, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_7$$6, (zephir_get_numberval(&_6$$6) - 1));
		ZVAL_LONG(&_8$$6, 1);
		zephir_substr(return_value, &_5$$6, zephir_get_intval(&_7$$6), 1 , 0);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("offset"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_10);
	ZVAL_LONG(&_10, (len + zephir_get_intval(&_9)));
	zephir_update_property_zval(this_ptr, SL("offset"), &_10);
	zephir_read_property(&_10, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_12, (zephir_get_numberval(&_11) - len));
	ZVAL_LONG(&_13, len);
	zephir_substr(return_value, &_10, zephir_get_intval(&_12), zephir_get_intval(&_13), 0);
	RETURN_MM();

}

/**
 * @return string
 * @throws BinaryDataException
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getRemaining) {

	zval str, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&str);
	zephir_substr(&str, &_0, zephir_get_intval(&_1), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&str)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pocketmine_utils_binarydataexception_ce, "No bytes left to read", "pocketmine/utils/binarystream.zep", 97);
		return;
	}
	zephir_read_property(&_2, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, zephir_fast_strlen_ev(&_2));
	zephir_update_property_zval(this_ptr, SL("offset"), &_3);
	RETURN_CCTOR(&str);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, put) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *str_param = NULL, _0, _1;
	zval str;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(&str, str_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &str);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getBool) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG_IDENTICAL(&_0, '\0'));

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putBool) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2;
	zend_bool v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_boolval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (v) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, '\1');
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, '\0');
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getByte) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ord", NULL, 16, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putByte) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, v);
	ZEPHIR_CALL_FUNCTION(&_2, "chr", NULL, 15, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_0, &_2);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_3);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getShort) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "n");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 130);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getSignedShort) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "n");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 135);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putShort) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "n");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getLShort) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "v");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 146);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getSignedLShort) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "v");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 151);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putLShort) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "v");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getTriad) {

	zval _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\0");
	ZEPHIR_CALL_FUNCTION(&_1, "chr", NULL, 15, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_2, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_1, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "N");
	ZEPHIR_CALL_FUNCTION(&_5, "unpack", NULL, 17, &_0, &_4);
	zephir_check_call_status();
	zephir_array_fetch_long(&_6, &_5, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 162);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putTriad) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	long v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "N");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &_3, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getLTriad) {

	zval _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 3);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\0");
	ZEPHIR_CALL_FUNCTION(&_3, "chr", NULL, 15, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "V");
	ZEPHIR_CALL_FUNCTION(&_5, "unpack", NULL, 17, &_2, &_4);
	zephir_check_call_status();
	zephir_array_fetch_long(&_6, &_5, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 172);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putLTriad) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4, _5;
	long v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "V");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_4, -1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &_3, 0 , -1 , 0);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_5);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getInt) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "N");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 182);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putInt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "N");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getLInt) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "V");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 193);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putLInt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	long v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "V");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getFloat) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "G");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 204);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getRoundedFloat) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *accuracy_param = NULL, _0, _1, _2, _3, _4;
	zend_long accuracy, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &accuracy_param);

	accuracy = zephir_get_intval(accuracy_param);


	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "G");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 209);
	ZVAL_LONG(&_1, accuracy);
	zephir_round(return_value, &_4, &_1, NULL);
	RETURN_MM();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putFloat) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "G");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getLFloat) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "g");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 219);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getRoundedLFloat) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *accuracy_param = NULL, _0, _1, _2, _3, _4;
	zend_long accuracy, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &accuracy_param);

	accuracy = zephir_get_intval(accuracy_param);


	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "g");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 224);
	ZVAL_LONG(&_1, accuracy);
	zephir_round(return_value, &_4, &_1, NULL);
	RETURN_MM();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putLFloat) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "g");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getDouble) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "E");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 234);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putDouble) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "E");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, getLDouble) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "e");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 244);
	RETURN_CTOR(&_4);

}

PHP_METHOD(Pocketmine_Utils_BinaryStream, putLDouble) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "e");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return int
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getLong) {

	zval _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_2, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_1, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_2);
	zephir_check_call_status();
	ZEPHIR_STATIC_RETURN_CALL_INTERNAL_METHOD_P1(pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readLong_zephir_internal_call, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param int $v
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, putLong) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "NN");
	ZVAL_LONG(&_2, (v >> 32));
	ZVAL_LONG(&_3, (v & 0xffffffff));
	ZEPHIR_CALL_FUNCTION(&_4, "pack", NULL, 18, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_0, &_4);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return int
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getLLong) {

	zval _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_2, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_1, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_2);
	zephir_check_call_status();
	ZEPHIR_STATIC_RETURN_CALL_INTERNAL_METHOD_P1(pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readLLong_zephir_internal_call, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param int $v
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, putLLong) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "VV");
	ZVAL_LONG(&_2, (v & 0xffffffff));
	ZVAL_LONG(&_3, (v >> 32));
	ZEPHIR_CALL_FUNCTION(&_4, "pack", NULL, 18, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_0, &_4);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 32-bit variable-length unsigned integer from the buffer and returns it.
 * @return int
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getUnsignedVarInt) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readUnsignedVarInt_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 32-bit variable-length unsigned integer to the end of the buffer.
 * @param int $v
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, putUnsignedVarInt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeUnsignedVarInt_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 32-bit zigzag-encoded variable-length integer from the buffer and returns it.
 * @return int
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getVarInt) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readVarInt_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 32-bit zigzag-encoded variable-length integer to the end of the buffer.
 * @param int $v
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, putVarInt) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeVarInt_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 64-bit variable-length integer from the buffer and returns it.
 * @return int
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getUnsignedVarLong) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readUnsignedVarLong_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 64-bit variable-length integer to the end of the buffer.
 * @param int $v
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, putUnsignedVarLong) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	long v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeUnsignedVarLong_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 64-bit zigzag-encoded variable-length integer from the buffer and returns it.
 * @return int
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, getVarLong) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readVarLong_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 64-bit zigzag-encoded variable-length integer to the end of the buffer.
 * @param int
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, putVarLong) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	long v;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v_param);

	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeVarLong_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether the offset has reached the end of the buffer.
 * @return bool
 */
PHP_METHOD(Pocketmine_Utils_BinaryStream, feof) {

	zval _1;
	zval _0, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC);
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CALL_FUNCTION(&_2, "str_split", NULL, 21, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("offset"), PH_NOISY_CC);
	RETURN_MM_BOOL(!(zephir_array_isset_long(&_2, zephir_get_intval(&_3))));

}

/**
 */
void zep_Pocketmine_Utils_BinaryStream_getOffset_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	

	RETURN_MEMBER(getThis(), "offset");

}

/**
 */
void zep_Pocketmine_Utils_BinaryStream_getBuffer_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	

	RETURN_MEMBER(getThis(), "buffer");

}

void zep_Pocketmine_Utils_BinaryStream_setOffset_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *offset_param_ext) {

	zval *offset_param = NULL, _0;
	long offset;
		ZVAL_UNDEF(&_0);

	offset_param = offset_param_ext;


	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, offset);
	zephir_update_property_zval(this_ptr, SL("offset"), &_0);

}

void zep_Pocketmine_Utils_BinaryStream_reset_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("buffer"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(this_ptr, SL("offset"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Rewinds the stream pointer to the start.
 */
void zep_Pocketmine_Utils_BinaryStream_rewind_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0;
		ZVAL_UNDEF(&_0);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, SL("offset"), &_0);

}

/**
 * @param int $len
 *
 * @return string
 *
 * @throws BinaryDataException if there are not enough bytes left in the buffer
 */
void zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *len_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, remaining, _0, _1, _9, _10, _11, _12, _13, _2$$5, _3$$5, _4$$5, _5$$6, _6$$6, _7$$6, _8$$6;
	long len;
		ZVAL_UNDEF(&remaining);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);

	ZEPHIR_MM_GROW();
	len_param = len_param_ext;


	len = zephir_get_intval(len_param);


	if (len == 0) {
		RETURN_MM_STRING("");
	}
	if (len < 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Length must be positive", "pocketmine/utils/binarystream.zep", 74);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&remaining);
	ZVAL_LONG(&remaining, (zephir_fast_strlen_ev(&_0) - zephir_get_numberval(&_1)));
	if (ZEPHIR_LT_LONG(&remaining, len)) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, pocketmine_utils_binarydataexception_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_LONG(&_3$$5, len);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_SVSV(&_4$$5, "Not enough bytes left in buffer: need ", &_3$$5, ", have ", &remaining);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 22, &_4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "pocketmine/utils/binarystream.zep", 79);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (len == 1) {
		RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("offset")));
		zephir_read_property(&_5$$6, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$6, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_7$$6, (zephir_get_numberval(&_6$$6) - 1));
		ZVAL_LONG(&_8$$6, 1);
		zephir_substr(return_value, &_5$$6, zephir_get_intval(&_7$$6), 1 , 0);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("offset"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_10);
	ZVAL_LONG(&_10, (len + zephir_get_intval(&_9)));
	zephir_update_property_zval(this_ptr, SL("offset"), &_10);
	zephir_read_property(&_10, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_12, (zephir_get_numberval(&_11) - len));
	ZVAL_LONG(&_13, len);
	zephir_substr(return_value, &_10, zephir_get_intval(&_12), zephir_get_intval(&_13), 0);
	RETURN_MM();

}

/**
 * @return string
 * @throws BinaryDataException
 */
void zep_Pocketmine_Utils_BinaryStream_getRemaining_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval str, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("offset"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&str);
	zephir_substr(&str, &_0, zephir_get_intval(&_1), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&str)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(pocketmine_utils_binarydataexception_ce, "No bytes left to read", "pocketmine/utils/binarystream.zep", 97);
		return;
	}
	zephir_read_property(&_2, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, zephir_fast_strlen_ev(&_2));
	zephir_update_property_zval(this_ptr, SL("offset"), &_3);
	RETURN_CCTOR(&str);

}

void zep_Pocketmine_Utils_BinaryStream_put_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *str_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *str_param = NULL, _0, _1;
	zval str;
		ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	str_param = str_param_ext;


	zephir_get_strval(&str, str_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, &str);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_1);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getBool_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_LONG_IDENTICAL(&_0, '\0'));

}

void zep_Pocketmine_Utils_BinaryStream_putBool_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2;
	zend_bool v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_boolval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	if (v) {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, '\1');
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, '\0');
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_2);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getByte_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ord", NULL, 16, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

void zep_Pocketmine_Utils_BinaryStream_putByte_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, v);
	ZEPHIR_CALL_FUNCTION(&_2, "chr", NULL, 15, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_0, &_2);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_3);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getShort_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "n");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 130);
	RETURN_CTOR(&_4);

}

void zep_Pocketmine_Utils_BinaryStream_getSignedShort_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "n");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 135);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

void zep_Pocketmine_Utils_BinaryStream_putShort_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "n");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getLShort_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "v");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 146);
	RETURN_CTOR(&_4);

}

void zep_Pocketmine_Utils_BinaryStream_getSignedLShort_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "v");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 151);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

void zep_Pocketmine_Utils_BinaryStream_putLShort_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "v");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getTriad_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\0");
	ZEPHIR_CALL_FUNCTION(&_1, "chr", NULL, 15, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_2, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_1, &_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "N");
	ZEPHIR_CALL_FUNCTION(&_5, "unpack", NULL, 17, &_0, &_4);
	zephir_check_call_status();
	zephir_array_fetch_long(&_6, &_5, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 162);
	RETURN_CTOR(&_6);

}

void zep_Pocketmine_Utils_BinaryStream_putTriad_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	long v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "N");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &_3, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getLTriad_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 3);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\0");
	ZEPHIR_CALL_FUNCTION(&_3, "chr", NULL, 15, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "V");
	ZEPHIR_CALL_FUNCTION(&_5, "unpack", NULL, 17, &_2, &_4);
	zephir_check_call_status();
	zephir_array_fetch_long(&_6, &_5, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 172);
	RETURN_CTOR(&_6);

}

void zep_Pocketmine_Utils_BinaryStream_putLTriad_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4, _5;
	long v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "V");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_4, -1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &_3, 0 , -1 , 0);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_5);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "N");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 182);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

void zep_Pocketmine_Utils_BinaryStream_putInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "N");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getLInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "V");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&temp);
	zephir_array_fetch_long(&temp, &_3, 1, PH_NOISY, "pocketmine/utils/binarystream.zep", 193);
	RETURN_MM_LONG((((zephir_get_intval(&temp) << 48)) >> 48));

}

void zep_Pocketmine_Utils_BinaryStream_putLInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	long v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "V");
	ZVAL_LONG(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getFloat_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "G");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 204);
	RETURN_CTOR(&_4);

}

void zep_Pocketmine_Utils_BinaryStream_getRoundedFloat_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *accuracy_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *accuracy_param = NULL, _0, _1, _2, _3, _4;
	zend_long accuracy, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	accuracy_param = accuracy_param_ext;


	accuracy = zephir_get_intval(accuracy_param);


	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "G");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 209);
	ZVAL_LONG(&_1, accuracy);
	zephir_round(return_value, &_4, &_1, NULL);
	RETURN_MM();

}

void zep_Pocketmine_Utils_BinaryStream_putFloat_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "G");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getLFloat_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "g");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 219);
	RETURN_CTOR(&_4);

}

void zep_Pocketmine_Utils_BinaryStream_getRoundedLFloat_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *accuracy_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *accuracy_param = NULL, _0, _1, _2, _3, _4;
	zend_long accuracy, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	accuracy_param = accuracy_param_ext;


	accuracy = zephir_get_intval(accuracy_param);


	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "g");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 224);
	ZVAL_LONG(&_1, accuracy);
	zephir_round(return_value, &_4, &_1, NULL);
	RETURN_MM();

}

void zep_Pocketmine_Utils_BinaryStream_putLFloat_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "g");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getDouble_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "E");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 234);
	RETURN_CTOR(&_4);

}

void zep_Pocketmine_Utils_BinaryStream_putDouble_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "E");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

void zep_Pocketmine_Utils_BinaryStream_getLDouble_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_1, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_0, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "e");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 17, &_2, &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 1, PH_NOISY | PH_READONLY, "pocketmine/utils/binarystream.zep", 244);
	RETURN_CTOR(&_4);

}

void zep_Pocketmine_Utils_BinaryStream_putLDouble_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *v_param = NULL, _0, _1, _2, _3, _4;
	double v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_doubleval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "e");
	ZVAL_DOUBLE(&_2, v);
	ZEPHIR_CALL_FUNCTION(&_3, "pack", NULL, 18, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_3);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return int
 */
void zep_Pocketmine_Utils_BinaryStream_getLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
		ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_2, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_1, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_2);
	zephir_check_call_status();
	ZEPHIR_STATIC_RETURN_CALL_INTERNAL_METHOD_P1(pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readLong_zephir_internal_call, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param int $v
 */
void zep_Pocketmine_Utils_BinaryStream_putLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "NN");
	ZVAL_LONG(&_2, (v >> 32));
	ZVAL_LONG(&_3, (v & 0xffffffff));
	ZEPHIR_CALL_FUNCTION(&_4, "pack", NULL, 18, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_0, &_4);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * @return int
 */
void zep_Pocketmine_Utils_BinaryStream_getLLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
		ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZVAL_LONG(&_2, 8);
	ZEPHIR_CALL_INTERNAL_METHOD_P1(&_1, this_ptr, zep_Pocketmine_Utils_BinaryStream_get_zephir_internal_call, &_2);
	zephir_check_call_status();
	ZEPHIR_STATIC_RETURN_CALL_INTERNAL_METHOD_P1(pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readLLong_zephir_internal_call, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param int $v
 */
void zep_Pocketmine_Utils_BinaryStream_putLLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *v_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "VV");
	ZVAL_LONG(&_2, (v & 0xffffffff));
	ZVAL_LONG(&_3, (v >> 32));
	ZEPHIR_CALL_FUNCTION(&_4, "pack", NULL, 18, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &_0, &_4);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_5);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 32-bit variable-length unsigned integer from the buffer and returns it.
 * @return int
 */
void zep_Pocketmine_Utils_BinaryStream_getUnsignedVarInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readUnsignedVarInt_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 32-bit variable-length unsigned integer to the end of the buffer.
 * @param int $v
 */
void zep_Pocketmine_Utils_BinaryStream_putUnsignedVarInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeUnsignedVarInt_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 32-bit zigzag-encoded variable-length integer from the buffer and returns it.
 * @return int
 */
void zep_Pocketmine_Utils_BinaryStream_getVarInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readVarInt_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 32-bit zigzag-encoded variable-length integer to the end of the buffer.
 * @param int $v
 */
void zep_Pocketmine_Utils_BinaryStream_putVarInt_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	zend_long v, ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeVarInt_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 64-bit variable-length integer from the buffer and returns it.
 * @return int
 */
void zep_Pocketmine_Utils_BinaryStream_getUnsignedVarLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readUnsignedVarLong_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 64-bit variable-length integer to the end of the buffer.
 * @param int $v
 */
void zep_Pocketmine_Utils_BinaryStream_putUnsignedVarLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	long v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeUnsignedVarLong_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads a 64-bit zigzag-encoded variable-length integer from the buffer and returns it.
 * @return int
 */
void zep_Pocketmine_Utils_BinaryStream_getVarLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval temp, result, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
		ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&temp);
	zephir_read_property(&temp, this_ptr, SL("offset"), PH_NOISY_CC);
	zval_ref_make(&temp);
	zephir_read_property(&_1, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P2(&result, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_readVarLong_zephir_internal_call, &_1, &temp);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("offset"), &temp);
	RETURN_MM_LONG(zephir_get_intval(&result));

}

/**
 * Writes a 64-bit zigzag-encoded variable-length integer to the end of the buffer.
 * @param int
 */
void zep_Pocketmine_Utils_BinaryStream_putVarLong_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used, zval *v_param_ext) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *v_param = NULL, _0, _1, _3, _4;
	long v;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	v_param = v_param_ext;


	v = zephir_get_intval(v_param);


	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, v);
	ZEPHIR_STATIC_CALL_INTERNAL_METHOD_P1(&_1, pocketmine_utils_binary_ce, zep_Pocketmine_Utils_Binary_writeVarLong_zephir_internal_call, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_0, &_1);
	zephir_update_property_zval(this_ptr, SL("buffer"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns whether the offset has reached the end of the buffer.
 * @return bool
 */
void zep_Pocketmine_Utils_BinaryStream_feof_zephir_internal_call(int ht, zend_execute_data *execute_data, zval *return_value, zval *this_ptr, int return_value_used) {

	zval _1;
	zval _0, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("buffer"), PH_NOISY_CC);
	zephir_get_strval(&_1, &_0);
	ZEPHIR_CALL_FUNCTION(&_2, "str_split", NULL, 21, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("offset"), PH_NOISY_CC);
	RETURN_MM_BOOL(!(zephir_array_isset_long(&_2, zephir_get_intval(&_3))));

}

