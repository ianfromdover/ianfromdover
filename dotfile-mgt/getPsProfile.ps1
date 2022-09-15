echo 'Getting powershell profile from location:'
echo $profile
$from = Get-Content -Path $profile
$to = '..\Microsoft.Powershell_profile.ps1'
Set-Content -Path $to $from
echo 'Git Powershell profile in repo has been updated!'

# idea: make the get and set scripts into an update script instead,
# compare the last modified date and use the later one to update the newer one
# for git, does a pull or a write constitute a last modified date? only works if
# a write is considered.

