import pandas as pd

def helper(row):
    for c in row['conditions'].split(' '):
        print(c)
        if c.startswith('DIAB1'):
            return True
    return False

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    condi=patients.apply(lambda row: helper(row),axis=1)
    return patients[condi]