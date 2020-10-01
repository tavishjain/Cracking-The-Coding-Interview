const ArrayString = require('./array-string');

const oneAwayModule = {
  /*
   * Given two strings, tell us if they are one edit away (or zero edits away)
   */
  isOneAway(str1, str2) {
    if (str1 === null || str2 === null) {
      throw new Error('str1 and/or str2 are null.');
    }

    if (typeof str1 !== 'string' || typeof str2 !== 'string') {
      throw new Error('str1 and/or str2 are not strings');
    }

    if (Math.abs(str1.length - str2.length) >= 2) {
      return false;
    }

    if (str1 === str2) {
      return true;
    }

    const arrayString1 = new ArrayString(str1);
    const arrayString2 = new ArrayString(str2);

    for (
      let index = 0;
      index < arrayString1.length() || index < arrayString2.length();
      index += 1) {
      if (index === arrayString1.length() || index === arrayString2.length()) {
        return true;
      }
      if (arrayString1.getCharAt(index) !== arrayString2.getCharAt(index)) {
        let substring1 = arrayString1.getSubString(index + 1, arrayString1.length() - 1);
        let substring2 = arrayString2.getSubString(index + 1, arrayString2.length() - 1);
        const replaceCase = this.areArraysEqual(substring1, substring2);

        substring1 = arrayString1.getSubString(index + 1, arrayString1.length() - 1);
        substring2 = arrayString2.getSubString(index, arrayString2.length() - 1);
        const insertCase = this.areArraysEqual(substring1, substring2);

        substring1 = arrayString1.getSubString(index, arrayString1.length() - 1);
        substring2 = arrayString2.getSubString(index + 1, arrayString2.length() - 1);
        const removeCase = this.areArraysEqual(substring1, substring2);

        return replaceCase || insertCase || removeCase;
      }
    }
    throw new Error('Should not reach this line');
  },
  /*
   * Given two input arrays, are they equal?
   * This is not a "deep equals" function.
   * If items in the array are objects or arrays, this function
   * will not give correct results.
   */
  areArraysEqual(array1, array2) {
    if (array1 === null || array2 === null) {
      throw new Error('array1 and/or array2 are null.');
    }

    if (!Array.isArray(array1) || !Array.isArray(array2)) {
      throw new Error('array1 and/or array2 are not arrays.');
    }

    if (array1.length === 0 && array2.length === 0) {
      return true;
    }

    if (array1.length !== array2.length) {
      return false;
    }

    for (let index = 0; index < array1.length; index += 1) {
      if (array1[index] !== array2[index]) {
        return false;
      }
    }
    return true;
  },
};

module.exports = oneAwayModule;
