const CheckPermutation = function () {};

/*
 * Checks to see if two input strings are permutations.
 * Returns true if they are, false otherwise.
 */
CheckPermutation.prototype.isPermutation = function (str1, str2) {
  if (typeof str1 !== 'string' || typeof str2 !== 'string') {
    throw Error('Either one or both inputs are not strings!');
  } else if (str1 === '' && str2 === '') {
    return true;
  } else if (str1.length !== str2.length) {
    return false;
  }

  return this.areDictsEqual(this.buildDict(str1), this.buildDict(str2));
};

/*
 * Helper function, takes in a string, and returns a dict
 * containing each unique character as a key, and the
 * number of times that character occurs in the string
 */
CheckPermutation.prototype.buildDict = function (str) {
  if (typeof str !== 'string') {
    throw new Error('input is not a string!');
  }

  const dict = {};

  for (let i = 0; i < str.length; i += 1) {
    if (dict[str[i]] === undefined) {
      dict[str[i]] = 1;
    } else {
      dict[str[i]] += 1;
    }
  }

  return dict;
};

/*
 * Given two dicts, are they equal?
 * Returns true if they are, false otherwise.
 */
CheckPermutation.prototype.areDictsEqual = function (dict1, dict2) {
  if (typeof dict1 !== 'object' || typeof dict2 !== 'object') {
    throw new Error('inputs are not dicts!');
  }

  const dict1Keys = Object.keys(dict1).sort();
  const dict2Keys = Object.keys(dict2).sort();
  const dict1Vals = Object.values(dict1);
  const dict2Vals = Object.values(dict2);

  if (dict1Keys.length === dict2Keys.length
    && dict1Vals.length === dict2Vals.length) {
    for (let i = 0; i < dict1Keys.length; i += 1) {
      if (dict1Keys[i] !== dict2Keys[i]
        || dict1[dict1Keys[i]] !== dict2[dict2Keys[i]]) {
        return false;
      }
    }

    return true;
  }

  return false;
};

module.exports = CheckPermutation;
