echo 'Setting powershell profile with location:'
echo $profile
$a = Get-Content -Path '..\Microsoft.Powershell_profile.ps1'
Set-Content -Path $profile $a
echo 'Powershell profile has been set'

# idea: make the get and set scripts into an update script instead,
# compare the last modified date and use the later one to update the newer one
# for git, does a pull or a write constitute a last modified date? only works if
# a write is considered.

