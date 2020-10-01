const palindromePermutation = {

    // Given a input string, tell us if this is a palindrome
    // permutation.
    //
    // The empty string is considered to be a palindrome, so
    // we return true in that case.
    isPalindromePermutation(inputString) {
      if (typeof inputString !== 'string') {
        throw new Error('Input must be a string!');
      }
  
      if (inputString === '') {
        return true;
      }
  
      return this.checkPalindromeCriteria(this.buildDict(inputString));
    },
  
    // Given an input string, give us the dict representation of
    // that string.
    //
    // Empty string -> empty dict.
    buildDict(inputString) {
      if (typeof inputString !== 'string') {
        throw new Error('Input must be a string!');
      }
  
      if (inputString === '') {
        return {};
      }
  
      const array = Array.from(inputString.toLowerCase());
      const retval = {};
  
      for (let i = 0; i < array.length; i += 1) {
        if (array[i] !== ' ') {
          if (retval[array[i]] === undefined) {
            retval[array[i]] = 1;
          } else {
            retval[array[i]] += 1;
          }
        }
      }
  
      return retval;
    },
  
    // Get the string's length, but ignoring spaces.
    // Our dicts already ignore the number of spaces,
    // so for every key, add up every value.
    getSumOfValues(dict) {
      if (typeof dict !== 'object') {
        throw new Error('Input must be a dict');
      }
  
      const keys = Object.keys(dict);
      let retval = 0;
  
      for (let i = 0; i < keys.length; i += 1) {
        retval += dict[keys[i]];
      }
  
      return retval;
    },
  
    // Given a dict representation, is this a valid palindrome
    // permutation?
    //
    // Empty dict -> true.
    checkPalindromeCriteria(dict) {
      if (typeof dict !== 'object') {
        throw new Error('Input must be a dict');
      }
  
      const stringLength = this.getSumOfValues(dict);
  
      if (dict === {}) {
        return true;
      }
  
      let numOddOccurences = 0;
  
      const keys = Object.keys(dict);
  
      for (let i = 0; i < keys.length; i += 1) {
        if (dict[keys[i]] % 2 !== 0) {
          numOddOccurences += 1;
        }
  
        if (stringLength % 2 === 0 && numOddOccurences > 0) {
          return false;
        }
  
        if (stringLength % 2 !== 0 && numOddOccurences > 1) {
          return false;
        }
      }
  
      return true;
    },
  };
  
  module.exports = palindromePermutation;
  