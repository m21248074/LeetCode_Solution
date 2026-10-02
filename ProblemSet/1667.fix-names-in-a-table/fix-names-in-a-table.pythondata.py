import pandas as pd

def helper(row):
    row['name']=row['name'][0].upper()+row['name'][1:].lower()
    return row

def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    return users.apply(lambda row: helper(row),axis=1).sort_values(by=['user_id'])