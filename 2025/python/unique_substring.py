def unique_substring(s: str) -> int:
    n = len(s)
    left = 0
    max_len = 0
    substring_chars = set()
    for right in range(n):
        if s[right] not in substring_chars:
            substring_chars.add(s[right])
            max_len = max(max_len, right - left + 1)
        else:
            while s[right] in substring_chars:
                substring_chars.remove(s[left])
                left += 1
            substring_chars.add(s[right])
            max_len = max(max_len, right - left + 1)
    return max_len

if __name__ == "__main__":
    print(unique_substring(input("Enter your string: ")))
