import requests

def extract_data(filename):
    parts = filename.split('_', 1)
    code = parts[0]
    if len(parts) > 1:
        problem = parts[1].replace('.cpp', '').replace('_', ' ')
    else:
        problem = ''
    return int(code), problem

def is_valid_filename(filename):
    return '_' in filename and filename.endswith('.cpp')

def get_repo_files(owner, repo):
    url = f"https://api.github.com/repos/{owner}/{repo}/contents"
    response = requests.get(url)
    if response.status_code == 200:
        files = response.json()
        for file in files:
            if is_valid_filename(file['name']): 
                repourl = "https://github.com/SABBIR-H0SSAIN/Leetcode-solutions/blob/main"
                code, problem = extract_data(file['name'])
                print(f"{code}. {problem}")
                print(f"{repourl}/{file['path']}")
                # print(f"{problem}")
            else:
                print(f"File {file['name']} does not match the expected format.")
    else:
        print(f"Error: {response.status_code}")

owner = "SABBIR-H0SSAIN"
repo = "leetcode-solutions"
get_repo_files(owner, repo)
