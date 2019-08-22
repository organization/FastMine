
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/math.h"


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
ZEPHIR_INIT_CLASS(Pocketmine_Math_VoxelRayTrace) {

	ZEPHIR_REGISTER_CLASS(Pocketmine\\Math, VoxelRayTrace, pocketmine, math_voxelraytrace, pocketmine_math_voxelraytrace_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * Performs a ray trace from the start position in the given direction, for a distance of $maxDistance. This
 * returns a Generator which yields Vector3s containing the coordinates of voxels it passes through.
 *
 * @param Vector3 $start
 * @param Vector3 $directionVector
 * @param float   $maxDistance
 *
 * @return \Generator|Vector3[]
 */
PHP_METHOD(Pocketmine_Math_VoxelRayTrace, inDirection) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	double maxDistance;
	zval *start, start_sub, *directionVector, directionVector_sub, *maxDistance_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&start_sub);
	ZVAL_UNDEF(&directionVector_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &start, &directionVector, &maxDistance_param);

	maxDistance = zephir_get_doubleval(maxDistance_param);


	ZVAL_DOUBLE(&_2, maxDistance);
	ZEPHIR_CALL_METHOD(&_1, directionVector, "multiply", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, start, "add", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("betweenpoints", NULL, 0, start, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Spaceship operator
 */
PHP_METHOD(Pocketmine_Math_VoxelRayTrace, spaceShip) {

	zval *a, a_sub, *b, b_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&a_sub);
	ZVAL_UNDEF(&b_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &a, &b);



	if (ZEPHIR_IS_EQUAL(a, b)) {
		RETURN_LONG(0);
	} else if (ZEPHIR_LT(a, b)) {
		RETURN_LONG(-1);
	} else {
		RETURN_LONG(1);
	}

}

/**
 * Performs a ray trace between the start and end coordinates. This returns a Generator which yields Vector3s
 * containing the coordinates of voxels it passes through.
 *
 * This is an implementation of the algorithm described in the link below.
 * @link http://www.cse.yorku.ca/~amana/research/grid.pdf
 *
 * @param Vector3 $start
 * @param Vector3 $end
 *
 * @return \Generator|Vector3[]
 */
PHP_METHOD(Pocketmine_Math_VoxelRayTrace, betweenPoints) {

	zend_bool _16$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, counter;
	zval *start, start_sub, *end, end_sub, tDeltaZ, tDeltaY, tDeltaX, tMaxZ, tMaxY, tMaxX, stepZ, stepY, stepX, radius, directionVector, currentBlock, _0, _1, _2, _3, _4, _5, _7, _8, _9, _10, _11, _12, _13, _14, _15, temp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&start_sub);
	ZVAL_UNDEF(&end_sub);
	ZVAL_UNDEF(&tDeltaZ);
	ZVAL_UNDEF(&tDeltaY);
	ZVAL_UNDEF(&tDeltaX);
	ZVAL_UNDEF(&tMaxZ);
	ZVAL_UNDEF(&tMaxY);
	ZVAL_UNDEF(&tMaxX);
	ZVAL_UNDEF(&stepZ);
	ZVAL_UNDEF(&stepY);
	ZVAL_UNDEF(&stepX);
	ZVAL_UNDEF(&radius);
	ZVAL_UNDEF(&directionVector);
	ZVAL_UNDEF(&currentBlock);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&temp);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &start, &end);



	ZEPHIR_CALL_METHOD(&currentBlock, start, "floor", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, end, "subtract", NULL, 0, start);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&directionVector, &_0, "normalize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &directionVector, "lengthsquared", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&_1, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Start and end points are the same, giving a zero direction vector", "pocketmine/math/voxelraytrace.zep", 74);
		return;
	}
	ZEPHIR_CALL_METHOD(&radius, start, "distance", NULL, 0, end);
	zephir_check_call_status();
	zephir_read_property(&_2, &directionVector, SL("x"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_CALL_FUNCTION(&stepX, "spaceship", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_read_property(&_3, &directionVector, SL("y"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_FUNCTION(&stepY, "spaceship", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property(&_4, &directionVector, SL("z"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, 0);
	ZEPHIR_CALL_FUNCTION(&stepZ, "spaceship", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	zephir_read_property(&_5, start, SL("x"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, &directionVector, SL("x"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&tMaxX, "raytracedistancetoboundary", &_6, 16, &_5, &_7);
	zephir_check_call_status();
	zephir_read_property(&_8, start, SL("y"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, &directionVector, SL("y"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&tMaxY, "raytracedistancetoboundary", &_6, 16, &_8, &_9);
	zephir_check_call_status();
	zephir_read_property(&_10, start, SL("z"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, &directionVector, SL("z"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_SELF(&tMaxZ, "raytracedistancetoboundary", &_6, 16, &_10, &_11);
	zephir_check_call_status();
	zephir_read_property(&_12, &directionVector, SL("x"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_12, 0)) {
		ZEPHIR_INIT_VAR(&tDeltaX);
		ZVAL_LONG(&tDeltaX, 0);
	} else {
		zephir_read_property(&_13, &directionVector, SL("x"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&tDeltaX);
		div_function(&tDeltaX, &stepX, &_13 TSRMLS_CC);
	}
	zephir_read_property(&_13, &directionVector, SL("y"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_13, 0)) {
		ZEPHIR_INIT_VAR(&tDeltaY);
		ZVAL_LONG(&tDeltaY, 0);
	} else {
		zephir_read_property(&_14, &directionVector, SL("y"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&tDeltaY);
		div_function(&tDeltaY, &stepY, &_14 TSRMLS_CC);
	}
	zephir_read_property(&_14, &directionVector, SL("z"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_14, 0)) {
		ZEPHIR_INIT_VAR(&tDeltaZ);
		ZVAL_LONG(&tDeltaZ, 0);
	} else {
		zephir_read_property(&_15, &directionVector, SL("z"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&tDeltaZ);
		div_function(&tDeltaZ, &stepZ, &_15 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&temp);
	array_init(&temp);
	counter = 0;
	while (1) {
		if (!(1)) {
			break;
		}
		counter++;
		zephir_array_update_long(&temp, counter, &currentBlock, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		_16$$4 = ZEPHIR_LT(&tMaxX, &tMaxY);
		if (_16$$4) {
			_16$$4 = ZEPHIR_LT(&tMaxX, &tMaxZ);
		}
		if (_16$$4) {
			if (ZEPHIR_GT(&tMaxX, &radius)) {
				break;
			}
			zephir_update_property_zval(&currentBlock, SL("x"), &stepX);
			ZEPHIR_ADD_ASSIGN(&tMaxX, &tDeltaX);
		} else if (ZEPHIR_LT(&tMaxY, &tMaxZ)) {
			if (ZEPHIR_GT(&tMaxY, &radius)) {
				break;
			}
			zephir_update_property_zval(&currentBlock, SL("y"), &stepY);
			ZEPHIR_ADD_ASSIGN(&tMaxY, &tDeltaY);
		} else {
			if (ZEPHIR_GT(&tMaxZ, &radius)) {
				break;
			}
			zephir_update_property_zval(&currentBlock, SL("z"), &stepZ);
			ZEPHIR_ADD_ASSIGN(&tMaxZ, &tDeltaZ);
		}
	}
	object_init_ex(return_value, zephir_get_internal_ce(SL("generator")));
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &temp);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * Returns the distance that must be travelled on an axis from the start point with the direction vector component to
 * cross a block boundary.
 *
 * For example, given an X coordinate inside a block and the X component of a direction vector, will return the distance
 * travelled by that direction component to reach a block with a different X coordinate.
 *
 * Find the smallest positive t such that s+t*ds is an integer.
 *
 * @param float $s Starting coordinate
 * @param float $ds Direction vector component of the relevant axis
 *
 * @return float Distance along the ray trace that must be travelled to cross a boundary.
 */
PHP_METHOD(Pocketmine_Math_VoxelRayTrace, rayTraceDistanceToBoundary) {

	zval s, *s_param = NULL, ds, *ds_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&ds);

	zephir_fetch_params_without_memory_grow(2, 0, &s_param, &ds_param);

	s = zephir_get_doubleval(s_param);
	ds = zephir_get_doubleval(ds_param);


	if (ZEPHIR_IS_LONG(&ds, 0)) {
		RETURN_DOUBLE(INF);
	}
	if (ZEPHIR_LT_LONG(&ds, 0)) {
		zephir_negate(&s TSRMLS_CC);
		zephir_negate(&ds TSRMLS_CC);
		if (ZEPHIR_IS_LONG(&s, zephir_floor(&s TSRMLS_CC))) {
			RETURN_DOUBLE(0.0);
		}
	}
	RETURN_DOUBLE(zephir_safe_div_double_zval((((double) 1 - ((zephir_get_numberval(&s) - zephir_floor(&s TSRMLS_CC))))), &ds TSRMLS_CC));

}
