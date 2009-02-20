/*
 Copyright 2008 - 2009 Sun Microsystems, Inc.

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; version 2 of the License.

 There are special exceptions to the terms and conditions of the GPL
 as it is applied to this software. View the full text of the
 exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
 software distribution.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 */

#include "../unit_fixture.h"

/**
 * Example of a collection of tests
 *
 */

namespace testsuite
{
namespace example
{

class example_test_class : public unit_fixture
{
private:
  typedef unit_fixture super;
protected:
public:

  EXAMPLE_TEST_FIXTURE(example_test_class)
  {
    TEST_CASE(test_hello_world1);
    TEST_CASE(test_hello_world2);
    TEST_CASE(test_assert_equals);
    TEST_CASE(test_assert_equals_fail);
    TEST_CASE(test_assert_message);
    TEST_CASE(test_assert_lessthan);
    TEST_CASE(test_assert_greaterthan);
    TEST_CASE(test_skip);
    TEST_CASE(test_todo);
  }

  /**
   * SELECT 'Hello world' example using framework magic
   *
   * Runs SELECT 'Hello world!' using the Connection and Statement
   * object that has been implicitly created by setUp() before calling the test.
   *
   * The unit_fixture class defines a coupld of useful members for you:
   * - Connection
   * - Statement
   * - PreparedStatement
   * - ResultSet
   *
   * The Connection object is the only one which is initialized and ready for
   * use. All other objects are in an undefined state. All members are defined
   * as auto-ptr, meaning, you don't need to worry about cleaning up them.
   */
  void test_hello_world1();

  /**
   * SELECT 'Hello world' example without framework magic
   *
   * The same as test1() but with less framework magic and, for example,
   * manual connect using the framework method getConnection()
   */
  void test_hello_world2();

  /**
   * Demo of ASSERT_EQUALS macro
   *
   * ASSERT_EQUALS macro can handle the following types:
   * - int
   * - bool
   * - double
   * - float
   * - long double
   * - char*
   *
   * ASSERT_EQUALS is a wrapper for:
   * void assertEquals(<type> expected, <type> result, const char* file, int line);
   */
  void test_assert_equals();

  /**
   * Demo of a failing ASSERT_EQUALS
   */
  void test_assert_equals_fail();

  /**
   * Demo of ASSERT_MESSAGE
   */
  void test_assert_message();

  /**
   * Demo of ASSERT_LT
   *
   * At the time of writing ASSERT_LT is only defined for int and unsigned int
   * comparisons. This has the nice  side effect that you can rewrite
   * "less or equal than" conditions as "less than" conditions.
   */
  void test_assert_lessthan();

  /**
   * Demo of ASSERT_GT
   *
   * At the time of writing ASSERT_GT is only defined for int and unsigned int
   * comparisons. This has the nice  side effect that you can rewrite
   * "greater or equal than" conditions as "greater than" conditions.
   */
  void test_assert_greaterthan();

  /**
   * Demo of SKIP(<message>)
   *
   * If a test requires a certain MySQL feature only available with MySQL version x.y.z
   * you should test if MySQL can give you what you need. If it can't SKIP the test.
   * SKIP will stop test execution.
   */
  void test_assert_skip();

  /**
   * Demo of TODO(<message>)
   *
   * If you know that a certain test will fail, for example, because its a regression
   * test for an open bug report, you should mark the test as a TODO. Whoever runs the
   * test will be able to see that you are working on the bug and the test failure
   * is expected and does not need to be escalated in any way.
   */
  void test_assert_todo();

};

REGISTER_FIXTURE(example_test_class);
} /* namespace example */
} /* namespace testsuite */
