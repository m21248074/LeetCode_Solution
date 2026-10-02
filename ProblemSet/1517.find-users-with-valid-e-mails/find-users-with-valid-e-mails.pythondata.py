import re
import pandas as pd

def helper(row: pd.Series) -> bool:
    pattern = r'^[A-Za-z]+[A-Za-z0-9\_\.\-]*@leetcode\.com$'
    return bool(re.match(pattern, row['mail']))

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    condi=users.apply(lambda row: helper(row),axis=1)
    return users[condi]